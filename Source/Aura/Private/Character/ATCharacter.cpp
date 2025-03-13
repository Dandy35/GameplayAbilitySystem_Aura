// Copyright Lazybolt Studios


#include "Character/ATCharacter.h"

#include "AbilitySystemComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/ATPlayerController.h"
#include "Player/ATPlayerState.h"
#include "UI/HUD/LB3HUD.h"

AATCharacter::AATCharacter()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	SpringArm->SetupAttachment(GetMesh());
	SpringArm->TargetArmLength = 800.f;
	SpringArm->bUsePawnControlRotation = false;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = false;
	
    GetCharacterMovement()->bOrientRotationToMovement = true;
    GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}

void AATCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// Init ability actor info for the server
	InitAbilityActorInfo();
}

void AATCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	//Init ability actor info for the client
	InitAbilityActorInfo();
}

void AATCharacter::InitAbilityActorInfo()
{
	AATPlayerState* ATPlayerState = GetPlayerState<AATPlayerState>();
	check (ATPlayerState)
	ATPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(ATPlayerState, this);
	AbilitySystemComponent = ATPlayerState->GetAbilitySystemComponent();
	AttributeSet = ATPlayerState->GetAttributeSet();

	if (AATPlayerController* ATPlayerController =  Cast<AATPlayerController>(GetController()))
	{
		if (ALB3HUD* LB3HUD = Cast<ALB3HUD>(ATPlayerController->GetHUD()))
		{
			LB3HUD->InitOverlay(ATPlayerController, ATPlayerState, AbilitySystemComponent, AttributeSet);
		}
	}
}


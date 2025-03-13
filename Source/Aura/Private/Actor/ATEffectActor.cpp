// Copyright Lazybolt Studios


#include "Actor/ATEffectActor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/ATAttributeSet.h"
#include "Components/SphereComponent.h"

AATEffectActor::AATEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
	
	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Sphere->SetupAttachment(RootComponent);
}

void AATEffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const UATAttributeSet* ATAttributeSet = Cast<UATAttributeSet>(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(UATAttributeSet::StaticClass()));
		
		UATAttributeSet* MutableATStatSet= const_cast<UATAttributeSet*>(ATAttributeSet);
		MutableATStatSet->SetHealth(ATAttributeSet->GetHealth() + 25.f);
		MutableATStatSet->SetMana(ATAttributeSet->GetMana() - 25.f);
		Destroy();
	}
}

void AATEffectActor::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	
}

void AATEffectActor::BeginPlay()
{
	Super::BeginPlay();
	
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AATEffectActor::OnOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AATEffectActor::EndOverlap);
}



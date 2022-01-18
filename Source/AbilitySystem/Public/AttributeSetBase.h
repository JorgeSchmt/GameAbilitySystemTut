// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AttributeSetBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHealthChangeDelegate, float, CurrentHealth, float, MaxHealth);

/**
 * 
 */
UCLASS()
class ABILITYSYSTEM_API UAttributeSetBase : public UAttributeSet
{
	GENERATED_BODY()

public:
	UAttributeSetBase();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AttributeSetBase")
	FGameplayAttributeData Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AttributeSetBase")
	FGameplayAttributeData MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AttributeSetBase")
	FGameplayAttributeData Mana;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AttributeSetBase")
	FGameplayAttributeData MaxMana;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AttributeSetBase")
	FGameplayAttributeData Strength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AttributeSetBase")
	FGameplayAttributeData MaxStrength;
	
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData &Data) override;

	UPROPERTY(BlueprintAssignable, Category="AttributeSetBase")
	FOnHealthChangeDelegate OnHealthChange;

	UPROPERTY(BlueprintAssignable, Category="AttributeSetBase")
	FOnHealthChangeDelegate OnManaChange;

	UPROPERTY(BlueprintAssignable, Category="AttributeSetBase")
	FOnHealthChangeDelegate OnStrengthChange;

	
};

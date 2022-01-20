// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilityTypes.h"

FGameplayAbilityInfo::FGameplayAbilityInfo()
	:CooldownDuration(0.0f),
	Cost(0.0f),
	CostType(EAbilityCostType::None),
	UIMat(nullptr),
	AbilityClass(nullptr)
{
}

FGameplayAbilityInfo::FGameplayAbilityInfo(float InCooldown, float InCost,
	EAbilityCostType InCostType, UMaterialInstance* InUIMat, TSubclassOf<UGameplayAbilityBase> InAbilityClass)
	:CooldownDuration(InCooldown),
	Cost(InCost),
	CostType(InCostType),
	UIMat(InUIMat),
	AbilityClass(InAbilityClass)
{
	
}

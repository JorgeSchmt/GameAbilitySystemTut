// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayAbilityBase.h"

FGameplayAbilityInfo UGameplayAbilityBase::GetAbilityInfo()
{
	UGameplayEffect* CooldownEffect = GetCooldownGameplayEffect();
	UGameplayEffect* CostEffect = GetCostGameplayEffect();

	if( CooldownEffect && CostEffect)
	{
		float CooldownDuration = 0.0f;
		CooldownEffect->DurationMagnitude.GetStaticMagnitudeIfPossible(1, CooldownDuration);

		float Cost = 0.0f;
		EAbilityCostType CostType = EAbilityCostType::None;
		if( CostEffect->Modifiers.Num() > 0)
		{
			const FGameplayModifierInfo EffectsInfo = CostEffect->Modifiers[0];
			EffectsInfo.ModifierMagnitude.GetStaticMagnitudeIfPossible(1, Cost);

			FGameplayAttribute CostAttr = EffectsInfo.Attribute;
			FString AttributeName = CostAttr.AttributeName;
			if( AttributeName == "Health")
			{
				CostType = EAbilityCostType::Health;
			}
			else if( AttributeName == "Mana")
			{
				CostType = EAbilityCostType::Mana;
			}
			else if( AttributeName == "Strength")
			{
				CostType = EAbilityCostType::Strength;
			}
		}
		return FGameplayAbilityInfo(CooldownDuration, Cost, CostType, UIMaterial, GetClass());
	}

	return FGameplayAbilityInfo();
}

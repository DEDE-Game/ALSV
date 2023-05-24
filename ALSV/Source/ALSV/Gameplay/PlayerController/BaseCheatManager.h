#pragma once
#include "CoreMinimal.h"
#include "GameFramework/CheatManager.h"
#include "BaseCheatManager.generated.h"


UCLASS(config = Engine)
class ALSV_API UBaseCheatManager : public UCheatManager
{
	GENERATED_UCLASS_BODY()
public:
	UFUNCTION(Exec)
	void ServerCmd(const FString& InCmd);
};

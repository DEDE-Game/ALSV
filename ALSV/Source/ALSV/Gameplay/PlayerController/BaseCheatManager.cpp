#include "BaseCheatManager.h"
#include "BasePlayerController.h"


UBaseCheatManager::UBaseCheatManager(const FObjectInitializer& ObjectInitializer /*= FObjectInitializer::Get()*/)
	:UCheatManager(ObjectInitializer)
{

}

void UBaseCheatManager::ServerCmd(const FString& InCmd)
{
	ABasePlayerController* pBaseController = Cast<ABasePlayerController>(GetOuter());
	if (IsValid(pBaseController))
	{
		if (pBaseController->GetLocalRole() == ENetRole::ROLE_AutonomousProxy )
		{
			pBaseController->Cmd_RPCToServerCmd(InCmd);
		}
	}
}

#include "BasePlayerController.h"
#include "Net/UnrealNetwork.h"


ABasePlayerController::ABasePlayerController(const FObjectInitializer& ObjectInitializer /*= FObjectInitializer::Get()*/)
: APlayerController(ObjectInitializer)
{
	bShowMouseCursor = true;
}

void ABasePlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (GetLocalRole() == ENetRole::ROLE_AutonomousProxy)
	{
		++LocalControllerNumber;
		ChangeControllerNumber(LocalControllerNumber);
	}
}

void ABasePlayerController::TickActor(float DeltaSeconds, ELevelTick TickType, FActorTickFunction& ThisTickFunction)
{
	Super::TickActor(DeltaSeconds, TickType, ThisTickFunction);
}

void ABasePlayerController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ABasePlayerController, TestControllerNumber);
}

void ABasePlayerController::ChangeControllerNumber_Implementation(int32 InNumber)
{
	TestControllerNumber = InNumber;
}

void ABasePlayerController::OnRep_ControllerNumberChanged()
{
	DebugLogALSVPlayerController("OnRep_ControllerNumberChanged AuthorityID:[%d], LocalID[%d]", TestControllerNumber, LocalControllerNumber);
}


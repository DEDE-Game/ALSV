#include "PlayerControllerDefine.h"
#include "Net/UnrealNetwork.h"


DEFINE_LOG_CATEGORY(ALSVPlayerController);

UMyTestObject::UMyTestObject(const FObjectInitializer& ObjectInitializer /*= FObjectInitializer::Get()*/)
	:UObject(ObjectInitializer)
{

}

UWorld* UMyTestObject::GetWorld() const
{
	if (const UObject* MyOuter = GetOuter())
	{
		return MyOuter->GetWorld();
	}
	return nullptr;
}

bool UMyTestObject::IsSupportedForNetworking() const
{
	return true;
}

void UMyTestObject::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UMyTestObject, bReplicatedFlag);
}

bool UMyTestObject::CallRemoteFunction(UFunction* Function, void* Parameters, struct FOutParmRec* OutParams, FFrame* Stack)
{
	if (AActor* OuterActor = Cast<AActor>(GetOuter()))
	{
		UNetDriver* NetDriver = OuterActor->GetNetDriver();
		if (NetDriver)
		{
			NetDriver->ProcessRemoteFunction(OuterActor, Function, Parameters, OutParams, Stack, this);
			return true;
		}
	}
	return false;
}

int32 UMyTestObject::GetFunctionCallspace(UFunction* Function, FFrame* Stack)
{
	if (AActor* OuterActor = Cast<AActor>(GetOuter()))
	{
		return OuterActor->GetFunctionCallspace(Function, Stack);
	}

	return FunctionCallspace::Local;
}

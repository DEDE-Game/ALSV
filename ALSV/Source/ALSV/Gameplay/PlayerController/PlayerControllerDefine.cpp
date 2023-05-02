#include "PlayerControllerDefine.h"
#include "Net/UnrealNetwork.h"


DEFINE_LOG_CATEGORY(ALSVPlayerController);

UMyTestObject::UMyTestObject(const FObjectInitializer& ObjectInitializer /*= FObjectInitializer::Get()*/)
	:UObject(ObjectInitializer)
{

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

bool UMyTestObject::ReplicateSubobjects(class UActorChannel* Channel, class FOutBunch* Bunch, FReplicationFlags* RepFlags)
{
	return true;
}


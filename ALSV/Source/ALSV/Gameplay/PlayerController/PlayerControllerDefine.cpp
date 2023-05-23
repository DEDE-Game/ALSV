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


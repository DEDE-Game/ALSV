#include "BaseGameInstance.h"
#include "GameFramework/GameModeBase.h"

DECLARE_LOG_CATEGORY_EXTERN(BaseGameInstance, Log, All);
DEFINE_LOG_CATEGORY(BaseGameInstance);


#define DebugLogGameInstance(format, ...) UE_LOG(BaseGameInstance, Log, TEXT(format), ##__VA_ARGS__)
#define WarningLogGameInstance(format, ...) UE_LOG(BaseGameInstance, Warning, TEXT(format), ##__VA_ARGS__)
#define ErrorLogGameInstance(format, ...) UE_LOG(BaseGameInstance, Error, TEXT(format), ##__VA_ARGS__)

#define BaseGameInstanceShowFuncName() \
	UE_LOG(BaseGameInstance, Log, TEXT("%s FrameNum[%lu]"), ANSI_TO_TCHAR(__FUNCTION__), GFrameNumber)

UBaseGameInstance::UBaseGameInstance(const FObjectInitializer& ObjectInitializer)
	:UGameInstance(ObjectInitializer)
{
#if !WITH_EDITOR
	float SleepTime = 20;
	for (int32 i = 0; i < SleepTime; ++i)
	{
		FPlatformProcess::Sleep(1);//单位秒
		DebugLogGameInstance("Already Sleep %ds", i);
	}
#endif

	BaseGameInstanceShowFuncName();
}

bool UBaseGameInstance::HandleOpenCommand(const TCHAR* Cmd, FOutputDevice& Ar, UWorld* InWorld)
{
	bool ret = Super::HandleOpenCommand(Cmd, Ar, InWorld);
	BaseGameInstanceShowFuncName();
	return ret;
}

bool UBaseGameInstance::HandleDisconnectCommand(const TCHAR* Cmd, FOutputDevice& Ar, UWorld* InWorld)
{
	bool ret = Super::HandleDisconnectCommand(Cmd, Ar, InWorld);
	BaseGameInstanceShowFuncName();
	return ret;
}

bool UBaseGameInstance::HandleReconnectCommand(const TCHAR* Cmd, FOutputDevice& Ar, UWorld* InWorld)
{
	bool ret = Super::HandleReconnectCommand(Cmd, Ar, InWorld);
	BaseGameInstanceShowFuncName();
	return ret;
}

bool UBaseGameInstance::HandleTravelCommand(const TCHAR* Cmd, FOutputDevice& Ar, UWorld* InWorld)
{
	bool ret = Super::HandleTravelCommand(Cmd, Ar, InWorld);
	BaseGameInstanceShowFuncName();
	return ret;
}

bool UBaseGameInstance::Exec(UWorld* InWorld, const TCHAR* Cmd, FOutputDevice& Out /*= *GLog*/)
{
	bool ret = Super::Exec(InWorld, Cmd, Out);
	BaseGameInstanceShowFuncName();
	return ret;
}

void UBaseGameInstance::FinishDestroy()
{
	Super::FinishDestroy();
	BaseGameInstanceShowFuncName();
}

void UBaseGameInstance::Init()
{
	Super::Init();
	BaseGameInstanceShowFuncName();
}

void UBaseGameInstance::Shutdown()
{
	Super::Shutdown();
	BaseGameInstanceShowFuncName();
}

void UBaseGameInstance::OnWorldChanged(UWorld* OldWorld, UWorld* NewWorld)
{
	Super::OnWorldChanged(OldWorld, NewWorld);
	BaseGameInstanceShowFuncName();
}

void UBaseGameInstance::StartGameInstance()
{
	Super::StartGameInstance();
	BaseGameInstanceShowFuncName();
}

bool UBaseGameInstance::JoinSession(ULocalPlayer* LocalPlayer, int32 SessionIndexInSearchResults)
{
	bool ret = Super::JoinSession(LocalPlayer, SessionIndexInSearchResults);
	BaseGameInstanceShowFuncName();
	return ret;
}

bool UBaseGameInstance::JoinSession(ULocalPlayer* LocalPlayer, const FOnlineSessionSearchResult& SearchResult)
{
	bool ret = Super::JoinSession(LocalPlayer, SearchResult);
	BaseGameInstanceShowFuncName();
	return ret;
}

void UBaseGameInstance::LoadComplete(const float LoadTime, const FString& MapName)
{
	Super::LoadComplete(LoadTime, MapName);
	BaseGameInstanceShowFuncName();
}

void UBaseGameInstance::DebugCreatePlayer(int32 ControllerId)
{
	Super::DebugCreatePlayer(ControllerId);
	BaseGameInstanceShowFuncName();
}

void UBaseGameInstance::DebugRemovePlayer(int32 ControllerId)
{
	Super::DebugCreatePlayer(ControllerId);
	BaseGameInstanceShowFuncName();
}

ULocalPlayer* UBaseGameInstance::CreateInitialPlayer(FString& OutError)
{
	auto ret = Super::CreateInitialPlayer(OutError);
	BaseGameInstanceShowFuncName();
	return ret;
}

int32 UBaseGameInstance::AddLocalPlayer(ULocalPlayer* NewPlayer, int32 ControllerId)
{
	auto ret = Super::AddLocalPlayer(NewPlayer, ControllerId);
	BaseGameInstanceShowFuncName();
	return ret;
}

bool UBaseGameInstance::RemoveLocalPlayer(ULocalPlayer* ExistingPlayer)
{
	auto ret = Super::RemoveLocalPlayer(ExistingPlayer);
	BaseGameInstanceShowFuncName();
	return ret;
}

void UBaseGameInstance::HandleDemoPlaybackFailure(EDemoPlayFailure::Type FailureType, const FString& ErrorString /*= TEXT("")*/)
{
	Super::HandleDemoPlaybackFailure(FailureType, ErrorString);
	BaseGameInstanceShowFuncName();
}

void UBaseGameInstance::OnSeamlessTravelDuringReplay()
{
	Super::OnSeamlessTravelDuringReplay();
	BaseGameInstanceShowFuncName();
}

void UBaseGameInstance::StartRecordingReplay(const FString& InName, const FString& FriendlyName, const TArray<FString>& AdditionalOptions /*= TArray<FString>()*/, TSharedPtr<IAnalyticsProvider> AnalyticsProvider /*= nullptr*/)
{
	Super::StartRecordingReplay(InName, FriendlyName, AdditionalOptions, AnalyticsProvider);
	BaseGameInstanceShowFuncName();
}

void UBaseGameInstance::StopRecordingReplay()
{
	Super::StopRecordingReplay();
	BaseGameInstanceShowFuncName();
}

bool UBaseGameInstance::PlayReplay(const FString& InName, UWorld* WorldOverride /*= nullptr*/, const TArray<FString>& AdditionalOptions /*= TArray<FString>()*/)
{
	auto ret = Super::PlayReplay(InName, WorldOverride, AdditionalOptions);
	BaseGameInstanceShowFuncName();
	return ret;
}

void UBaseGameInstance::AddUserToReplay(const FString& UserString)
{
	Super::AddUserToReplay(UserString);
	BaseGameInstanceShowFuncName();
}

void UBaseGameInstance::HandleGameNetControlMessage(class UNetConnection* Connection, uint8 MessageByte, const FString& MessageStr)
{
	Super::HandleGameNetControlMessage(Connection, MessageByte, MessageStr);
	BaseGameInstanceShowFuncName();
}

void UBaseGameInstance::ReceivedNetworkEncryptionToken(const FString& EncryptionToken, const FOnEncryptionKeyResponse& Delegate)
{
	Super::ReceivedNetworkEncryptionToken(EncryptionToken, Delegate);
	BaseGameInstanceShowFuncName();
}

void UBaseGameInstance::ReceivedNetworkEncryptionAck(const FOnEncryptionKeyResponse& Delegate)
{
	Super::ReceivedNetworkEncryptionAck(Delegate);
	BaseGameInstanceShowFuncName();
}

void UBaseGameInstance::PreloadContentForURL(FURL InURL)
{
	Super::PreloadContentForURL(InURL);
	BaseGameInstanceShowFuncName();
}

class AGameModeBase* UBaseGameInstance::CreateGameModeForURL(FURL InURL, UWorld* InWorld)
{
	auto ret = Super::CreateGameModeForURL(InURL, InWorld);
	BaseGameInstanceShowFuncName();
	return ret;
}

TSubclassOf<AGameModeBase> UBaseGameInstance::OverrideGameModeClass(TSubclassOf<AGameModeBase> GameModeClass, const FString& MapName, const FString& Options, const FString& Portal) const
{
	auto ret = Super::OverrideGameModeClass(GameModeClass, MapName, Options, Portal);
	BaseGameInstanceShowFuncName();
	return ret;
}

bool UBaseGameInstance::DelayPendingNetGameTravel()
{
	auto ret = Super::DelayPendingNetGameTravel();
	BaseGameInstanceShowFuncName();
	return ret;
}

TSubclassOf<UOnlineSession> UBaseGameInstance::GetOnlineSessionClass()
{
	auto ret = Super::GetOnlineSessionClass();
	BaseGameInstanceShowFuncName();
	return ret;
}

FName UBaseGameInstance::GetOnlinePlatformName() const
{
	auto ret = Super::GetOnlinePlatformName();
	BaseGameInstanceShowFuncName();
	return ret;
}

bool UBaseGameInstance::ClientTravelToSession(int32 ControllerId, FName InSessionName)
{
	auto ret = Super::ClientTravelToSession(ControllerId, InSessionName);
	BaseGameInstanceShowFuncName();
	return ret;
}

void UBaseGameInstance::ReturnToMainMenu()
{
	Super::ReturnToMainMenu();
	BaseGameInstanceShowFuncName();
}

void UBaseGameInstance::RegisterReferencedObject(UObject* ObjectToReference)
{
	Super::RegisterReferencedObject(ObjectToReference);
	BaseGameInstanceShowFuncName();
}

void UBaseGameInstance::UnregisterReferencedObject(UObject* ObjectToReference)
{
	Super::UnregisterReferencedObject(ObjectToReference);
	BaseGameInstanceShowFuncName();
}

void UBaseGameInstance::OnStart()
{
	Super::OnStart();
	BaseGameInstanceShowFuncName();
}

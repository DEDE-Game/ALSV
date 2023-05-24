#pragma once
#include "CoreMinimal.h"
#include "Engine/ActorChannel.h"
#include "Net/DataBunch.h"
#include "Engine/EngineTypes.h"
#include "PlayerControllerDefine.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(ALSVPlayerController, Log, All);

#define DebugLogALSVPlayerController(format, ...) UE_LOG(ALSVPlayerController, Log, TEXT(format), ##__VA_ARGS__)
#define WarningALSVPlayerController(format, ...) UE_LOG(ALSVPlayerController, Warning, TEXT(format), ##__VA_ARGS__)
#define ErrorLogALSVPlayerController(format, ...) UE_LOG(ALSVPlayerController, Error, TEXT(format), ##__VA_ARGS__)




// 道具 附加数据类型
UENUM(BlueprintType)
enum class EMyTestEnum : uint8
{
	ENone			UMETA(DisplayName = "None"),
	ETest1			UMETA(DisplayName = "测试1"),
	ETest2			UMETA(DisplayName = "测试2"),
};

USTRUCT(BlueprintType)
struct FMyTestDataBase
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
		int32 BaseMemberInt = 0;
	UPROPERTY(BlueprintReadWrite)
		bool BaseMemberBool = false;
	UPROPERTY(BlueprintReadWrite)
		FName BaseMemberName;
	UPROPERTY(BlueprintReadWrite)
		float BaseMemberFloat = 0.1;
	UPROPERTY(BlueprintReadWrite)
		EMyTestEnum BaseMemberEnum = EMyTestEnum::ENone;
};

USTRUCT(BlueprintType)
struct FMyTestDataItem
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
		int32 DataItemInt = 0;
	UPROPERTY(BlueprintReadWrite)
		bool DataItemBool = false;
	UPROPERTY(BlueprintReadWrite)
		FName DataItemName;
	UPROPERTY(BlueprintReadWrite)
		float DataItemFloat = 0.1;
	UPROPERTY(BlueprintReadWrite)
		EMyTestEnum DataItemEnum = EMyTestEnum::ENone;
};

USTRUCT(BlueprintType)
struct FMyTestData : public FMyTestDataBase
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
		int32 MemberInt = 0;
	UPROPERTY(BlueprintReadWrite)
		bool MemberBool = false;
	UPROPERTY(BlueprintReadWrite)
		FName MemberName;
	UPROPERTY(BlueprintReadWrite)
		float MemberFloat = 0.1;
	UPROPERTY(BlueprintReadWrite)
		EMyTestEnum MemberEnum = EMyTestEnum::ENone;

	UPROPERTY(BlueprintReadWrite)
		TArray<FMyTestDataItem> ItemList;

	UPROPERTY(BlueprintReadWrite)
		TArray<UObject*> ObjList;
};

UCLASS(BlueprintType, Blueprintable)
class UMyTestObject : public UObject
{
	GENERATED_BODY()
public:
	UMyTestObject(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	// Allows the Object to get a valid UWorld from it's outer.
	virtual UWorld* GetWorld() const override;

	// allow replicate data
	virtual bool IsSupportedForNetworking() const override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	// allow rpc
	int32 GetFunctionCallspace(UFunction* Function, FFrame* Stack);
	bool CallRemoteFunction(UFunction* Function, void* Parameters, struct FOutParmRec* OutParams, FFrame* Stack);

public:
	UPROPERTY(Replicated)
	uint32 bReplicatedFlag : 1;

	UPROPERTY(BlueprintReadWrite)
		TArray<FMyTestDataItem> ItemList;
};


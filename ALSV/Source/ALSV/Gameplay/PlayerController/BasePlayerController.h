#pragma once
#include "GameFramework/PlayerController.h"
#include "PlayerControllerDefine.h"
#include "TestReplicationComp.h"
#include "TestFastArray.h"
#include "GameFramework/HUD.h"

#include "BasePlayerController.generated.h"


UCLASS(BlueprintType, Blueprintable)
class ABasePlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	ABasePlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	virtual void Tick(float DeltaSeconds) override;
	virtual void TickActor(float DeltaSeconds, ELevelTick TickType, FActorTickFunction& ThisTickFunction) override;
	
public:
	virtual void AddCheats(bool bForce = false) override;


public:
	virtual void ClientSetHUD_Implementation(TSubclassOf<AHUD> NewHUDClass) override;
	virtual void DisplayDebug(class UCanvas* Canvas, const FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos) override;


public:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual bool ReplicateSubobjects(UActorChannel* Channel, FOutBunch* Bunch, FReplicationFlags* RepFlags) override;

public:
	UFUNCTION(Server, Reliable)
	void Cmd_RPCToServerCmd(const FString &InCmd);

public:
	UFUNCTION(Server, Reliable)
	void ChangeControllerNumber(int32 InNumber);

	void TestSparseArray();
	void TestFastArray();

	bool bAddFastArrayItem = true;
public:
	UPROPERTY()
	UTestReplicationComp *TestReplicationComp1;

	UPROPERTY()
		UTestReplicationComp* TestReplicationComp2;

public:
	UPROPERTY(ReplicatedUsing = OnRep_ControllerNumberChanged)
		int32 TestControllerNumber = 0;
	UFUNCTION()
		void OnRep_ControllerNumberChanged();

	UPROPERTY(ReplicatedUsing = OnRep_ExampleFastArray)
		FExampleArray ExampleFastArray;
	UFUNCTION()
		void OnRep_ExampleFastArray();


	UPROPERTY(ReplicatedUsing = OnRep_ExampleStruct)
		FExampleStruct ExampleStruct;
	UFUNCTION()
		void OnRep_ExampleStruct();

	UPROPERTY(ReplicatedUsing = OnRep_ExampleStruct1)
		FExampleStruct1 ExampleStruct1;
	UFUNCTION()
		void OnRep_ExampleStruct1();

public:
	UPROPERTY(ReplicatedUsing = OnRep_TestObj)
		UMyTestObject *pTestObj = 0;

	UFUNCTION()
	void OnRep_TestObj();


	UPROPERTY(ReplicatedUsing = OnRep_TestData)
		FMyTestData TestData;

	UFUNCTION()
		void OnRep_TestData();


	UPROPERTY(ReplicatedUsing = OnRep_TestDataList)
		TArray<FMyTestData> TestDataList;

	UFUNCTION()
		void OnRep_TestDataList();

	UPROPERTY(Replicated)
		int32 TestIntArray[3] ;

	UPROPERTY(Replicated)
		FMyTestData MyTestDataArray[3];


public:
	int32 LocalControllerNumber = 0;

};

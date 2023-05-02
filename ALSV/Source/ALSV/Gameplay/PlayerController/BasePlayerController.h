#pragma once
#include "GameFramework/PlayerController.h"
#include "PlayerControllerDefine.h"

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
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:
	UFUNCTION(Server, Reliable)
	void ChangeControllerNumber(int32 InNumber);


public:
	UPROPERTY(ReplicatedUsing = OnRep_ControllerNumberChanged)
		int32 TestControllerNumber = 0;

	UFUNCTION()
		void OnRep_ControllerNumberChanged();

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

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

	UFUNCTION()
	void OnRep_ControllerNumberChanged();

public:
	UPROPERTY(ReplicatedUsing = OnRep_ControllerNumberChanged, EditAnywhere, BlueprintReadOnly, Category = AttrConfig)
		int32 TestControllerNumber = 0;

	int32 LocalControllerNumber = 0;

};

#include "BaseAnimInstance.h"
#include "Components/SkeletalMeshComponent.h"

#define EnableAnimInstanceShowFuncName 0

#define AnimInstanceShowFuncName() \
if (EnableAnimInstanceShowFuncName==1) \
{\
	FString DebugInfo = GetDebugInfo(); \
	UE_LOG(AnimInstance, Log, TEXT("%s FrameNum[%lu] ObjName[%s] %s"), ANSI_TO_TCHAR(__FUNCTION__), GFrameNumber, *GetName(), *DebugInfo)\
}\
else \
{ \
}



FString UBaseAnimInstance::GetDebugInfo() const
{
	FString DebugInfo = "None";
	USkeletalMeshComponent *OwnerComponent = Cast<USkeletalMeshComponent>(GetOuter());
	if (IsValid(OwnerComponent))
	{
		AActor* OwnerActor = OwnerComponent->GetOwner();
		if (IsValid(OwnerActor))
		{
			FString OwnerName = OwnerActor->GetName();
			FString RoleType;
			switch (OwnerActor->GetLocalRole())
			{
			case  ENetRole::ROLE_None: { RoleType = "ROLE_None"; break; }
			case  ENetRole::ROLE_SimulatedProxy: { RoleType = "ROLE_SimulatedProxy"; break; }
			case  ENetRole::ROLE_AutonomousProxy: { RoleType = "ROLE_AutonomousProxy"; break; }
			case  ENetRole::ROLE_Authority: { RoleType = "ROLE_Authority"; break; }
			}
			
			DebugInfo = FString::Printf(TEXT("OwnerName[%s] RoleType[%s]"), *OwnerName, *RoleType);
		}
	}

	return DebugInfo;
}

void UBaseAnimInstance::SavePoseSnapshot(FName SnapshotName)
{
	Super::SavePoseSnapshot(SnapshotName);
	AnimInstanceShowFuncName();
}

void UBaseAnimInstance::SnapshotPose(FPoseSnapshot& Snapshot)
{
	Super::SnapshotPose(Snapshot);
	AnimInstanceShowFuncName();
}

bool UBaseAnimInstance::CanRunParallelWork() const
{
	Super::CanRunParallelWork();
	AnimInstanceShowFuncName();
	return true;
}

void UBaseAnimInstance::OnMontageInstanceStopped(FAnimMontageInstance& StoppedMontageInstance)
{
	Super::OnMontageInstanceStopped(StoppedMontageInstance);
	AnimInstanceShowFuncName();
}

void UBaseAnimInstance::Montage_UpdateWeight(float DeltaSeconds)
{
	Super::Montage_UpdateWeight(DeltaSeconds);
	AnimInstanceShowFuncName();
}

void UBaseAnimInstance::Montage_Advance(float DeltaSeconds)
{
	Super::Montage_Advance(DeltaSeconds);
	AnimInstanceShowFuncName();
}

void UBaseAnimInstance::BeginDestroy()
{
	AnimInstanceShowFuncName();
	Super::BeginDestroy();
}

void UBaseAnimInstance::PostInitProperties()
{
	Super::PostInitProperties();
	AnimInstanceShowFuncName();
}

#if WITH_EDITORONLY_DATA
bool UBaseAnimInstance::PCV_ShouldWarnAboutNodesNotUsingFastPath() const
{
	bool bRet = Super::PCV_ShouldWarnAboutNodesNotUsingFastPath();
	AnimInstanceShowFuncName();
	return bRet;
}

bool UBaseAnimInstance::PCV_ShouldNotifyAboutNodesNotUsingFastPath() const
{
	bool bRet = Super::PCV_ShouldNotifyAboutNodesNotUsingFastPath();
	AnimInstanceShowFuncName();
	return false;
}

void UBaseAnimInstance::ApplyAnimOverridesToCDO(FCompilerResultsLog& MessageLog)
{
	Super::ApplyAnimOverridesToCDO(MessageLog);
	AnimInstanceShowFuncName();
}
#endif // WITH_EDITORONLY_DATA

void UBaseAnimInstance::OnUROSkipTickAnimation()
{
	Super::OnUROSkipTickAnimation();
	AnimInstanceShowFuncName();
}

void UBaseAnimInstance::OnUROPreInterpolation_AnyThread(FAnimationEvaluationContext& InOutContext)
{
	Super::OnUROPreInterpolation_AnyThread(InOutContext);
	AnimInstanceShowFuncName();
}

void UBaseAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	AnimInstanceShowFuncName();
}

void UBaseAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	AnimInstanceShowFuncName();
}

void UBaseAnimInstance::NativePostEvaluateAnimation()
{
	Super::NativePostEvaluateAnimation();
	AnimInstanceShowFuncName();
}

void UBaseAnimInstance::NativeUninitializeAnimation()
{
	Super::NativeUninitializeAnimation();
	AnimInstanceShowFuncName();
}

void UBaseAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();
	AnimInstanceShowFuncName();
}

void UBaseAnimInstance::DisplayDebugInstance(FDisplayDebugManager& DisplayDebugManager, float& Indent)
{
	Super::DisplayDebugInstance(DisplayDebugManager, Indent);
	AnimInstanceShowFuncName();
}

int32 UBaseAnimInstance::GetLODLevel() const
{
	int32 n = Super::GetLODLevel();
	AnimInstanceShowFuncName();
	return n;
}

bool UBaseAnimInstance::HandleNotify(const FAnimNotifyEvent& AnimNotifyEvent)
{
	bool b = Super::HandleNotify(AnimNotifyEvent);
	AnimInstanceShowFuncName();
	return b;
}

void UBaseAnimInstance::PreUpdateAnimation(float DeltaSeconds)
{
	Super::PreUpdateAnimation(DeltaSeconds);
	AnimInstanceShowFuncName();
}

FAnimInstanceProxy* UBaseAnimInstance::CreateAnimInstanceProxy()
{
	FAnimInstanceProxy *p = Super::CreateAnimInstanceProxy();
	AnimInstanceShowFuncName();
	return p;
}

void UBaseAnimInstance::DestroyAnimInstanceProxy(FAnimInstanceProxy* InProxy)
{
	Super::DestroyAnimInstanceProxy(InProxy);
	AnimInstanceShowFuncName();
}

bool UBaseAnimInstance::ShouldTriggerAnimNotifyState(const UAnimNotifyState* AnimNotifyState) const
{
	bool bRet = Super::ShouldTriggerAnimNotifyState(AnimNotifyState);
	AnimInstanceShowFuncName();
	return bRet;
}


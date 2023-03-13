#pragma once
#include "Animation/AnimInstance.h"
#include "AnimDefine.h"
#include "BaseAnimInstance.generated.h"


UCLASS(BlueprintType)
class UBaseAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	FString GetDebugInfo() const;

	virtual void SavePoseSnapshot(FName SnapshotName) override;

	/**
	 * Takes a snapshot of the current skeletal mesh component pose and saves it to the specified snapshot.
	 * The snapshot is taken at the current LOD, so if for example you took the snapshot at LOD1
	 * and then used it at LOD0 any bones not in LOD1 will use the reference pose
	 */
	virtual void SnapshotPose(UPARAM(ref) FPoseSnapshot& Snapshot) override;

	// Can this animation instance run Update or Evaluation work in parallel
	virtual bool CanRunParallelWork() const override ;

	virtual void OnMontageInstanceStopped(FAnimMontageInstance& StoppedMontageInstance) override;

	/** Update weight of montages  **/
	virtual void Montage_UpdateWeight(float DeltaSeconds) override;
	/** Advance montages **/
	virtual void Montage_Advance(float DeltaSeconds) override;

public:
	//~ Begin UObject Interface
	virtual void BeginDestroy() override;
	virtual void PostInitProperties() override;
	//~ End UObject Interface

#if WITH_EDITORONLY_DATA // ANIMINST_PostCompileValidation

	/** Warn if AnimNodes are not using fast path during AnimBP compilation. */
	virtual bool PCV_ShouldWarnAboutNodesNotUsingFastPath() const override;
	virtual bool PCV_ShouldNotifyAboutNodesNotUsingFastPath() const override;

	// Called on the newly created CDO during anim blueprint compilation to allow subclasses a chance to replace animations (experimental)
	virtual void ApplyAnimOverridesToCDO(FCompilerResultsLog& MessageLog) override;
#endif // WITH_EDITORONLY_DATA

	/** Called when skipping an animation update because of URO. */
	virtual void OnUROSkipTickAnimation() override;

	/**
	 * Called before URO interpolation is performed. Useful for modifying bone space transforms etc. before interpolation is performed.
	 * Note that this can be called on a worker thread.
	 */
	virtual void OnUROPreInterpolation_AnyThread(FAnimationEvaluationContext& InOutContext) override;


	// the below functions are the native overrides for each phase
	// Native initialization override point
	virtual void NativeInitializeAnimation() override;
	// Native update override point. It is usually a good idea to simply gather data in this step and 
	// for the bulk of the work to be done in NativeUpdateAnimation.
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	// Native Post Evaluate override point
	virtual void NativePostEvaluateAnimation() override;
	// Native Uninitialize override point
	virtual void NativeUninitializeAnimation() override;

	// Executed when begin play is called on the owning component
	virtual void NativeBeginPlay() override;

	// Display debug info about AnimInstance. Can be overridden to add custom info from child classes.
	virtual void DisplayDebugInstance(FDisplayDebugManager& DisplayDebugManager, float& Indent) override;

	/**
	 * Get the 'animation' LOD level, which by default is the PredictedLODLevel of this anim instance's skeletal mesh component.
	 * This function is used by the anim graph to determine the LOD level at which to run.
	 * @return the current LOD level
	 */
	virtual int32 GetLODLevel() const override;

protected:
	/** Implementable custom function to handle notifies */
	virtual bool HandleNotify(const FAnimNotifyEvent& AnimNotifyEvent) override;

protected:
	/** Called to setup for updates */
	virtual void PreUpdateAnimation(float DeltaSeconds) override;

	/** Override point for derived classes to create their own proxy objects (allows custom allocation) */
	virtual FAnimInstanceProxy* CreateAnimInstanceProxy() override;

	/** Override point for derived classes to destroy their own proxy objects (allows custom allocation) */
	virtual void DestroyAnimInstanceProxy(FAnimInstanceProxy* InProxy) override;

	/** Return whether this AnimNotifyState should be triggered */
	virtual bool ShouldTriggerAnimNotifyState(const UAnimNotifyState* AnimNotifyState) const;


};

#include "BasePlayerController.h"
#include "Net/UnrealNetwork.h"
#include "Containers/SparseArray.h"
#include "Net/Core/PushModel/PushModel.h"
#include "BaseCheatManager.h"
#include "Engine/Canvas.h"
#include "DisplayDebugHelpers.h"


ABasePlayerController::ABasePlayerController(const FObjectInitializer& ObjectInitializer /*= FObjectInitializer::Get()*/)
: APlayerController(ObjectInitializer)
{
	bShowMouseCursor = true;

	TestReplicationComp1 = CreateDefaultSubobject<UTestReplicationComp>(TEXT("TestReplicationComp1"));
	TestReplicationComp2 = CreateDefaultSubobject<UTestReplicationComp>(TEXT("TestReplicationComp2"));

	CheatClass = UBaseCheatManager::StaticClass();
}

void ABasePlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (GetLocalRole() == ENetRole::ROLE_AutonomousProxy)
	{
		++LocalControllerNumber;
		ChangeControllerNumber(LocalControllerNumber);

	}

	if (GetLocalRole() == ENetRole::ROLE_Authority)
	{
		TestSparseArray();
		TestFastArray();

		if (pTestObj==nullptr)
		{
			pTestObj = NewObject<UMyTestObject>(this, UMyTestObject::StaticClass());
		}

		if (pTestObj->ItemList.Num()==0)
		{
			FMyTestDataItem Item1;
			Item1.DataItemInt = 1;
			Item1.DataItemFloat = 0.1;
			pTestObj->ItemList.Add(Item1);
			Item1.DataItemInt = 2;
			Item1.DataItemFloat = 0.2;
			pTestObj->ItemList.Add(Item1);
		}
		else
		{
			for (FMyTestDataItem &Item : pTestObj->ItemList)
			{
				++Item.DataItemInt;
				Item.DataItemBool = !Item.DataItemBool;
				Item.DataItemFloat += 0.1;
			}
		}

		if (TestData.ItemList.Num()<=0)
		{
			TestData.MemberInt = 1;
			TestData.MemberBool = !TestData.MemberBool;
			TestData.MemberFloat += 0.1;

			FMyTestDataItem Item;
			Item.DataItemInt += 1;
			Item.DataItemFloat += 1;
			Item.DataItemBool = !Item.DataItemBool;

			TestData.ItemList.Add(Item);

			Item.DataItemInt += 1;
			Item.DataItemFloat += 1;
			Item.DataItemBool = !Item.DataItemBool;
			TestData.ItemList.Add(Item);

			{
				UMyTestObject* pTempTestObj = NewObject<UMyTestObject>(this, UMyTestObject::StaticClass());
				Item.DataItemInt += 100;
				Item.DataItemFloat += 100;
				Item.DataItemBool = !Item.DataItemBool;
				pTempTestObj->ItemList.Add(Item);

				Item.DataItemInt += 100;
				Item.DataItemFloat += 100;
				Item.DataItemBool = !Item.DataItemBool;
				pTempTestObj->ItemList.Add(Item);
				TestData.ObjList.Add(pTempTestObj);
			}
		}
		else
		{
			TestData.MemberInt = 1;
			TestData.MemberBool = !TestData.MemberBool;
			TestData.MemberFloat += 0.1;

			
			for (FMyTestDataItem& TempItem : TestData.ItemList)
			{
				TempItem.DataItemInt += 2;
				TempItem.DataItemFloat += 2.0;
			}
		}

		if (TestDataList.Num()<=0)
		{
			FMyTestData MyTestData;
			MyTestData.MemberInt = 99;
			MyTestData.MemberFloat = 99.0;

			FMyTestDataItem MyTestDataItem;
			MyTestDataItem.DataItemInt = 999;
			MyTestData.ItemList.Add(MyTestDataItem);

			MyTestDataItem.DataItemInt = 1999;
			MyTestData.ItemList.Add(MyTestDataItem);

			UMyTestObject* pTempTestObj = NewObject<UMyTestObject>(this, UMyTestObject::StaticClass());
			pTempTestObj->ItemList.Add(MyTestDataItem);

			TestDataList.Add(MyTestData);

			TestDataList.Add(MyTestData);
		}
		else
		{
			FMyTestData &MyTestData = TestDataList[1];
			MyTestData.MemberInt += 100;

			FMyTestDataItem &MyTestDataItem = MyTestData.ItemList[0];
			MyTestDataItem.DataItemInt += 1000.0;
		}
	}
}

void ABasePlayerController::TickActor(float DeltaSeconds, ELevelTick TickType, FActorTickFunction& ThisTickFunction)
{
	Super::TickActor(DeltaSeconds, TickType, ThisTickFunction);
}

void ABasePlayerController::AddCheats(bool bForce /*= false*/)
{
	CheatManager = NewObject<UCheatManager>(this, CheatClass);
	CheatManager->InitCheatManager();
}

void ABasePlayerController::ClientSetHUD_Implementation(TSubclassOf<AHUD> NewHUDClass)
{
	Super::ClientSetHUD_Implementation(NewHUDClass);
}

void ABasePlayerController::DisplayDebug(class UCanvas* Canvas, const FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos)
{
	// 使用ShowDebug命令
	Super::DisplayDebug(Canvas, DebugDisplay, YL, YPos);

	FDisplayDebugManager& DisplayDebugManager = Canvas->DisplayDebugManager;
	{ // show debug test
		static FName Test("Test");
		if (DebugDisplay.IsDisplayOn(Test))
		{
			DisplayDebugManager.SetDrawColor(FColor::Red);
			DisplayDebugManager.DrawString(FString(TEXT("<<<< Test >>>>")));
		}
	}
	
}

void ABasePlayerController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ABasePlayerController, TestControllerNumber);
	DOREPLIFETIME(ABasePlayerController, pTestObj);
	DOREPLIFETIME(ABasePlayerController, TestData);
	DOREPLIFETIME(ABasePlayerController, TestDataList);

	FDoRepLifetimeParams SharedParams;
	SharedParams.bIsPushBased = true;
	DOREPLIFETIME_WITH_PARAMS_FAST(ABasePlayerController, ExampleFastArray, SharedParams);
	DOREPLIFETIME_WITH_PARAMS_FAST(ABasePlayerController, ExampleStruct, SharedParams);
	DOREPLIFETIME_WITH_PARAMS_FAST(ABasePlayerController, ExampleStruct1, SharedParams);
}

bool ABasePlayerController::ReplicateSubobjects(UActorChannel* Channel, FOutBunch* Bunch, FReplicationFlags* RepFlags)
{
	bool bWroteSomething = Super::ReplicateSubobjects(Channel, Bunch, RepFlags);

	// Single Object
	bWroteSomething |= Channel->ReplicateSubobject(pTestObj, *Bunch, *RepFlags);

	return bWroteSomething;
}

void ABasePlayerController::Cmd_RPCToServerCmd_Implementation(const FString& InCmd)
{
	ConsoleCommand(InCmd, true);
}

void ABasePlayerController::ChangeControllerNumber_Implementation(int32 InNumber)
{
	TestControllerNumber = InNumber;
}

void ABasePlayerController::TestSparseArray()
{


}

void ABasePlayerController::TestFastArray()
{
	++ExampleStruct.ExampleIntProperty;
	MARK_PROPERTY_DIRTY_FROM_NAME(ABasePlayerController, ExampleStruct, this);

	++ExampleStruct1.ExampleIntProperty;
	MARK_PROPERTY_DIRTY_FROM_NAME(ABasePlayerController, ExampleStruct1, this);

	if (bAddFastArrayItem)
	{
		FExampleItemEntry Item;
		Item.ExampleFloatProperty = 1;
		Item.ExampleFloatProperty = 2;
		int32 ItemIndex = ExampleFastArray.Items.Add(Item);
		ExampleFastArray.MarkItemDirty(ExampleFastArray.Items[ItemIndex]);
		if (ExampleFastArray.Items.Num()>=5)
		{
			bAddFastArrayItem = false;
		}
	}
	else
	{
		if (ExampleFastArray.Items.Num()>0)
		{
			ExampleFastArray.Items.RemoveAt(0);
			ExampleFastArray.MarkArrayDirty();
		}

		if (ExampleFastArray.Items.Num()==0)
		{
			bAddFastArrayItem = true;
		}
	}
}

void ABasePlayerController::OnRep_ControllerNumberChanged()
{
	DebugLogALSVPlayerController("OnRep_ControllerNumberChanged AuthorityID:[%d], LocalID[%d]", TestControllerNumber, LocalControllerNumber);
}

void ABasePlayerController::OnRep_ExampleFastArray()
{
	DebugLogALSVPlayerController("OnRep_ExampleFastArray");
}

void ABasePlayerController::OnRep_ExampleStruct()
{
	DebugLogALSVPlayerController("OnRep_ExampleStruct");
}

void ABasePlayerController::OnRep_ExampleStruct1()
{
	DebugLogALSVPlayerController("OnRep_ExampleStruct1");
}

void ABasePlayerController::OnRep_TestObj()
{
	DebugLogALSVPlayerController("OnRep_TestObj");
}

void ABasePlayerController::OnRep_TestData()
{
	DebugLogALSVPlayerController("OnRep_TestData");

}

void ABasePlayerController::OnRep_TestDataList()
{
	DebugLogALSVPlayerController("OnRep_TestDataList");

}


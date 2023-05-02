#include "BasePlayerController.h"
#include "Net/UnrealNetwork.h"


ABasePlayerController::ABasePlayerController(const FObjectInitializer& ObjectInitializer /*= FObjectInitializer::Get()*/)
: APlayerController(ObjectInitializer)
{
	bShowMouseCursor = true;
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

void ABasePlayerController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ABasePlayerController, TestControllerNumber);
	DOREPLIFETIME(ABasePlayerController, pTestObj);
	DOREPLIFETIME(ABasePlayerController, TestData);
	DOREPLIFETIME(ABasePlayerController, TestDataList);
}

void ABasePlayerController::ChangeControllerNumber_Implementation(int32 InNumber)
{
	TestControllerNumber = InNumber;
}

void ABasePlayerController::OnRep_ControllerNumberChanged()
{
	DebugLogALSVPlayerController("OnRep_ControllerNumberChanged AuthorityID:[%d], LocalID[%d]", TestControllerNumber, LocalControllerNumber);
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


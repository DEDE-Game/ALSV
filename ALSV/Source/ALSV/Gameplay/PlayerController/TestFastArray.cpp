#include "TestFastArray.h"

DECLARE_LOG_CATEGORY_EXTERN(FastArrayLog, Log, All);
DEFINE_LOG_CATEGORY(FastArrayLog);


#define DebugLogFastArray(format, ...) UE_LOG(FastArrayLog, Log, TEXT(format), ##__VA_ARGS__)
#define WarningFastArray(format, ...) UE_LOG(FastArrayLog, Warning, TEXT(format), ##__VA_ARGS__)
#define ErrorLogFastArray(format, ...) UE_LOG(FastArrayLog, Error, TEXT(format), ##__VA_ARGS__)



void FExampleItemEntry::PreReplicatedRemove(const struct FExampleArray& InArraySerializer)
{
	DebugLogFastArray("PreReplicatedRemove");
}

void FExampleItemEntry::PostReplicatedAdd(const struct FExampleArray& InArraySerializer)
{
	DebugLogFastArray("PostReplicatedAdd");
}

void FExampleItemEntry::PostReplicatedChange(const struct FExampleArray& InArraySerializer)
{
	DebugLogFastArray("PostReplicatedChange");
}

FString FExampleItemEntry::GetDebugString()
{
	DebugLogFastArray("GetDebugString");
	return FString(TEXT("FExampleItemEntry"));
}

bool FExampleArray::NetDeltaSerialize(FNetDeltaSerializeInfo& DeltaParms)
{
	DebugLogFastArray("NetDeltaSerialize");
	return FFastArraySerializer::FastArrayDeltaSerialize<FExampleItemEntry, FExampleArray>(Items, DeltaParms, *this);
}

bool FExampleStruct::NetSerialize(FArchive& Ar, class UPackageMap* Map, bool& bOutSuccess)
{
	Ar<<ExampleIntProperty;
	DebugLogFastArray("NetSerialize");

	bOutSuccess = true;
	return true;
}

bool FExampleStruct::NetDeltaSerialize(FNetDeltaSerializeInfo& DeltaParms)
{
	DebugLogFastArray("NetDeltaSerialize");
	return true;
}

bool FExampleStruct::Identical(const FExampleStruct* Other, uint32 PortFlags) const
{
	return ExampleIntProperty == Other->ExampleIntProperty;
}

void FExampleStruct::operator=(const FExampleStruct& Other)
{
	ExampleIntProperty = Other.ExampleIntProperty;
}

bool FExampleStruct1::NetSerialize(FArchive& Ar, class UPackageMap* Map, bool& bOutSuccess)
{
	Ar << ExampleIntProperty;
	DebugLogFastArray("FExampleStruct1:NetDeltaSerialize");
	return true;
}

bool FExampleStruct1::NetDeltaSerialize(FNetDeltaSerializeInfo& DeltaParms)
{
	DebugLogFastArray("FExampleStruct1:NetDeltaSerialize");
	return true;
}

#pragma once


DECLARE_LOG_CATEGORY_EXTERN(AnimInstance, Log, All);

#define DebugLogAnimInstance(format, ...) UE_LOG(AnimInstance, Log, TEXT(format), ##__VA_ARGS__)
#define WarningLogAnimInstance(format, ...) UE_LOG(AnimInstance, Warning, TEXT(format), ##__VA_ARGS__)
#define ErrorLogAnimInstance(format, ...) UE_LOG(AnimInstance, Error, TEXT(format), ##__VA_ARGS__)



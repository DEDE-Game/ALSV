#pragma once

DECLARE_LOG_CATEGORY_EXTERN(ALSVCharacter, Log, All);

#define DebugLogALSVCharacter(format, ...) UE_LOG(ALSVCharacter, Log, TEXT(format), ##__VA_ARGS__)
#define WarningALSVCharacter(format, ...) UE_LOG(ALSVCharacter, Warning, TEXT(format), ##__VA_ARGS__)
#define ErrorLogALSVCharacter(format, ...) UE_LOG(ALSVCharacter, Error, TEXT(format), ##__VA_ARGS__)



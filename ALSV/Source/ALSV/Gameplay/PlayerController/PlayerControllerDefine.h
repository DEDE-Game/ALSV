#pragma once

DECLARE_LOG_CATEGORY_EXTERN(ALSVPlayerController, Log, All);

#define DebugLogALSVPlayerController(format, ...) UE_LOG(ALSVPlayerController, Log, TEXT(format), ##__VA_ARGS__)
#define WarningALSVPlayerController(format, ...) UE_LOG(ALSVPlayerController, Warning, TEXT(format), ##__VA_ARGS__)
#define ErrorLogALSVPlayerController(format, ...) UE_LOG(ALSVPlayerController, Error, TEXT(format), ##__VA_ARGS__)




:: 设置地图为/Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap
:: 设置GameMode为GAME=/Game/GamePlay/NewGameMode.NewGameMode_C
:: 启动log
:: InitialConnectTimeout=30
start E:\Documents\WorkDir\ALSV_Win64PackageList\WindowsNoEditor\ALSV\Binaries\Win64\ALSVServer.exe ^
/Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap^
?GAME=/Game/GamePlay/NewGameMode.NewGameMode_C^
?InitialConnectTimeout=30^
 -Port=7778^
 -MULTIHOME=127.0.0.1^
 -log

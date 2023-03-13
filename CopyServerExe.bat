

set SrcDir="E:\Documents\WorkDir\ALSV\ALSV"
set TargetDir="E:\Documents\WorkDir\ALSV_Win64PackageList"

set TargetPath=%TargetDir%"\WindowsNoEditor\ALSV\Binaries\Win64\"
copy %SrcDir%\Binaries\Win64\ALSVServer.exe %TargetPath%
copy %SrcDir%\Binaries\Win64\ALSVServer.exp %TargetPath%
copy %SrcDir%\Binaries\Win64\ALSVServer.lib %TargetPath%
copy %SrcDir%\Binaries\Win64\ALSVServer.pdf %TargetPath%
copy %SrcDir%\Binaries\Win64\ALSVServer.target %TargetPath%

pause
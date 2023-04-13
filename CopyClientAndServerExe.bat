

set SrcDir=E:\Documents\WorkDir\ALSV\ALSV
set TargetDir=E:\Documents\WorkDir\ALSV_Win64PackageList

set TargetPath=%TargetDir%\WindowsNoEditor\ALSV\Binaries\Win64\

set ServerFileName=ALSVServer
set ClientFileName=ALSV

del /a /f %TargetPath%\%ServerFileName%.exe 
del /a /f %TargetPath%\%ServerFileName%.exp 
del /a /f %TargetPath%\%ServerFileName%.lib 
del /a /f %TargetPath%\%ServerFileName%.pdb 


del /a /f %TargetPath%\%ClientFileName%.exe 
del /a /f %TargetPath%\%ClientFileName%.exp 
del /a /f %TargetPath%\%ClientFileName%.lib 
del /a /f %TargetPath%\%ClientFileName%.pdb 

copy %SrcDir%\Binaries\Win64\%ServerFileName%.exe %TargetPath%
copy %SrcDir%\Binaries\Win64\%ServerFileName%.exp %TargetPath%
copy %SrcDir%\Binaries\Win64\%ServerFileName%.lib %TargetPath%
copy %SrcDir%\Binaries\Win64\%ServerFileName%.pdb %TargetPath%


copy %SrcDir%\Binaries\Win64\%ClientFileName%.exe %TargetPath%
copy %SrcDir%\Binaries\Win64\%ClientFileName%.exp %TargetPath%
copy %SrcDir%\Binaries\Win64\%ClientFileName%.lib %TargetPath%
copy %SrcDir%\Binaries\Win64\%ClientFileName%.pdb %TargetPath%

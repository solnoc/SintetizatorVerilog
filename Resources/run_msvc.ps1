$folderPath = Get-Location
$compilerExe = "& 'C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.42.34433\bin\Hostx64\x64\cl.exe'"
$linkerExe = "& 'C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.42.34433\bin\Hostx64\x64\link.exe'"


$outputFolder = Join-Path -Path $folderPath -ChildPath "realease"
$debugMode = ""
foreach ($arg in $args) {
    if ($arg -eq "-d") {
        $debugMode = "/DEBUG"
        $outputFolder = Join-Path -Path $folderPath -ChildPath "debug"
    }
}
$compilerOptimization = "-O2"
foreach ($arg in $args) {
    if ($arg -eq "-O0") {
        $compilerOptimization = "-O0"
        break
    }
    elseif($arg -eq "-O1"){
        $compilerOptimization = "-O1"
        break
    }
}
$debugOptions = "$debugMode" #$compilerOptimization"

$cppFiles = Get-ChildItem -Path $folderPath -Filter "*.cpp"

$fileArray = @()
foreach ($cppFile in $cppFiles){
    $fileArray += $cppFile.Name
}
$cppFilesToCompile = $fileArray -join " "

$libraryFolder = Join-Path -Path $folderPath -ChildPath "lib\sfml-windows"
$gppCommandCompile = "$compilerExe /Zi /Gd /Od /c $cppFilesToCompile /I$libraryFolder\include"
Invoke-Expression $gppCommandCompile

Write-Output "Compiled project into object file"
$objectArray = @()
foreach ($cppFile in $cppFiles){
    $objectArray +=  [System.IO.Path]::ChangeExtension($cppFile.Name, ".obj")
}
$objectFilesToLink = $objectArray -join " "

$linkerFlags = "sfml-graphics.lib sfml-window.lib sfml-system.lib"
$gppCommandLink = "$linkerExe $debugOptions /OUT:$outputFolder\sintetizator.exe $objectFilesToLink /LIBPATH:$libraryFolder\lib $linkerFlags"

if(!(Test-Path -Path $outputFolder -PathType Container)){
    New-Item $outputFolder -ItemType Container
}
Invoke-Expression $gppCommandLink

Copy-Item -Path (Join-Path -Path $libraryFolder -ChildPath "bin\sfml-graphics-2.dll") -Destination $outputFolder
Copy-Item -Path (Join-Path -Path $libraryFolder -ChildPath "bin\sfml-window-2.dll") -Destination $outputFolder
Copy-Item -Path (Join-Path -Path $libraryFolder -ChildPath "bin\sfml-system-2.dll") -Destination $outputFolder

foreach ($object in $objectArray){
    Remove-Item (Join-Path -Path $folderPath -ChildPath $object)
}

if(!(Test-Path -Path "$outputFolder\assets" -PathType Container)){
    New-Item "$outputFolder\assets" -Itemtype Container
}

$pngFiles = Get-ChildItem -Path "$folderPath\assets" -Filter "*.png"
foreach($pngFile in $pngFiles){
    Copy-Item -Path $pngFile.FullName -Destination "$outputFolder\assets"
}

Write-Output "Linked object files into executable"

$substOutput = subst
if (!$substOutput -contains "W:") { subst W: C:\Users\rober\Projects\SintetizatorVerilog\ }
cd W:\
$env:PATH += ";W:\Resources\bin"
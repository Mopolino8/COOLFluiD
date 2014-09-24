#!MC 1000
$!VarSet |MFBD| = '/home/user/workspace/COOLFluiD/app/core'
$!ALTERDATA 
  EQUATION = '{M}=sqrt(({u}**2+{v}**2+{w}**2)/(287.046*1.4*{T}))'
$!ALTERDATA 
  EQUATION = '{rho}={p}/({T}*287.046)'
$!ALTERDATA 
  EQUATION = '{Tt} = {T}*(1. + 0.2*{M}**2.)'
$!ALTERDATA 
  EQUATION = '{pt} = {p}*(1. + 0.2*{M}**2.)**3.5'
$!ALTERDATA 
  EQUATION = '{s} = log({p})-1.4*log({rho})'
$!GLOBALCONTOUR 1  VAR = 3
$!CONTOURLEVELS RESETTONICE
  CONTOURGROUP = 1
  APPROXNUMVALUES = 15
$!GLOBALCONTOUR 1  VAR = 7
$!CONTOURLEVELS RESETTONICE
  CONTOURGROUP = 1
  APPROXNUMVALUES = 15
$!FIELDLAYERS SHOWCONTOUR = YES
$!FIELDLAYERS SHOWMESH = NO
$!RemoveVar |MFBD|
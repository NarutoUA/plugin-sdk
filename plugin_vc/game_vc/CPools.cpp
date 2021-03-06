/*
    Plugin-SDK (Grand Theft Auto) source file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/
#include "CPools.h"

CPool<CBuilding>  *&CPools::ms_pBuildingPool =  *(CPool<CBuilding> **)0x97F240;
CPool<CTreadable> *&CPools::ms_pTreadablePool = *(CPool<CTreadable> **)0x978834;
CPool<CEntryInfoNode> *&CPools::ms_pEntryInfoNodePool = *(CPool<CEntryInfoNode> **)0xA0D8BC;
CPool<CPtrNode> *&CPools::ms_pPtrNodePool = *(CPool<CPtrNode> **)0xA0FD38;
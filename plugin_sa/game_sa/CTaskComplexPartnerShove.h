/*
    Plugin-SDK (Grand Theft Auto) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/
#pragma once

#include "plbase/PluginBase_SA.h"
#include "CTaskComplexPartner.h"

class PLUGIN_API CTaskComplexPartnerShove : public CTaskComplexPartner {
protected:
    CTaskComplexPartnerShove(plugin::dummy_func_t a) : CTaskComplexPartner(a) {}
public:
    
};

//VALIDATE_SIZE(CTaskComplexPartnerShove, 0x);
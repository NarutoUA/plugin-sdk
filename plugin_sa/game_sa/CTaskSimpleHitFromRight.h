/*
    Plugin-SDK (Grand Theft Auto) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/
#pragma once

#include "plbase/PluginBase_SA.h"
#include "CTaskSimpleRunAnim.h"

class PLUGIN_API CTaskSimpleHitFromRight : public CTaskSimpleRunAnim {
protected:
    CTaskSimpleHitFromRight(plugin::dummy_func_t a) : CTaskSimpleRunAnim(a) {}
public:
    
};

//VALIDATE_SIZE(CTaskSimpleHitFromRight, 0x);
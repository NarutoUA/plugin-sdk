/*
    Plugin-SDK (Grand Theft Auto) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/
#pragma once

#include "game_vc\CPools.h"
#include "..\shared\Extender.h"
#include "events\Events_VC.h"
#include <vector>

class CObject;

namespace plugin {
    class ObjectExtendersHandler : public ExtendersHandler<CObject> {
    public:
        static void Add(ExtenderInterface<CObject> *extender) {
            extenders.push_back(extender);
            if (!injected) {
                plugin::Events::initPoolsEvent.after += Allocate;
                plugin::Events::objectCtorEvent.before += Constructor;
                plugin::Events::objectDtorEvent.after += Destructor;
                injected = true;
            }
        }
    };

    std::vector<ExtenderInterface<CObject> *> ObjectExtendersHandler::extenders;
    bool ObjectExtendersHandler::injected;

    template <typename T> class ObjectExtendedData : public ExtenderInterface<CObject> {
        T **blocks;
        unsigned int numBlocks;

        void AllocateBlocks() {
            numBlocks = CPools::ms_pObjectPool->m_Size;
            blocks = new T*[numBlocks];
            for (unsigned int i = 0; i < numBlocks; i++)
                blocks[i] = 0;
        }

        void OnConstructor(CObject *object) {
            blocks[CPools::ms_pObjectPool->GetArrayIndex(object)] = new T(object);
        }

        void OnDestructor(CObject *object) {
            delete blocks[CPools::ms_pObjectPool->GetArrayIndex(object)];
            blocks[CPools::ms_pObjectPool->GetArrayIndex(object)] = 0;
        }
    public:
        ObjectExtendedData() {
            blocks = 0;
            ObjectExtendersHandler::Add(this);
        }

        ~ObjectExtendedData() {
            for (unsigned int i = 0; i < numBlocks; i++)
                delete blocks[i];
            delete[] blocks;
        }

        T &Get(CObject *object) {
            return *blocks[CPools::ms_pObjectPool->GetArrayIndex(object)];
        }
    };
}
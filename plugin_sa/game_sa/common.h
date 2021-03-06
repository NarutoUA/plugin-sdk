/*
    Plugin-SDK (Grand Theft Auto) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/
#include "plbase/PluginBase_SA.h"
#include "CVector.h"
#include "CEntity.h"
#include "CPed.h"
#include "CVehicle.h"
#include "CWeaponInfo.h"
#include "CAnimBlendClumpData.h"

// returns player coors
PLUGIN_API CVector FindPlayerCoors(int playerId);
// returns player speed
PLUGIN_API CVector const& FindPlayerSpeed(int playerId);
// returns player ped or player vehicle if he's driving
PLUGIN_API CEntity * FindPlayerEntity(int playerId);
// gets player coords
PLUGIN_API CVector const& FindPlayerCentreOfWorld(int playerId);
// gets player coords with skipping sniper shift
PLUGIN_API CVector const& FindPlayerCentreOfWorld_NoSniperShift(int playerId);
// returns player coords with skipping interior shift
PLUGIN_API CVector FindPlayerCentreOfWorld_NoInteriorShift(int playerId);
// returns player angle in radians
PLUGIN_API float FindPlayerHeading(int playerId);
// returns Z coord for active player
PLUGIN_API float FindPlayerHeight();
// returns player ped
PLUGIN_API CPed * FindPlayerPed(int playerId = -1);
// returns player vehicle
PLUGIN_API CVehicle * FindPlayerVehicle(int playerId, bool bIncludeRemote);
// 2 players are playing
PLUGIN_API bool InTwoPlayersMode();
// vectorsub
PLUGIN_API CVector VectorSub(CVector const& from, CVector const& what);
// matrix mul
PLUGIN_API CVector Multiply3x3(CMatrix  const& matrix, CVector  const& vec);

PLUGIN_API extern uint32_t &ClumpOffset;

#define RpClumpGetAnimBlendClumpData(clump) (*(CAnimBlendClumpData **)(((unsigned int)(clump) + ClumpOffset)))

PLUGIN_API AnimBlendFrameData *RpAnimBlendClumpFindFrame(RpClump *clump, char *name);

PLUGIN_API char *MakeUpperCase(char *dest, char *src);

// dummy function
void CreateDebugFont();
// dummy function
void DestroyDebugFont();
// dummy function
void ObrsPrintfString(char const* arg0, short arg1, short arg2);
// dummy function
void FlushObrsPrintfs();
void DefinedState();
void DefinedState2d();
RpAtomic* GetFirstAtomicCallback(RpAtomic* atomic, void* data);
RpAtomic* GetFirstAtomic(RpClump* clump);
RpAtomic* Get2DEffectAtomicCallback(RpAtomic* atomic, void* data);
RpAtomic* Get2DEffectAtomic(RpClump* clump);
RwObject* GetFirstObjectCallback(RwObject* object, void* data);
RwObject* GetFirstObject(RwFrame* frame);
RwFrame* GetFirstFrameCallback(RwFrame* frame, void* data);
RwFrame* GetFirstChild(RwFrame* frame);
RwTexture* GetFirstTextureCallback(RwTexture* texture, void* data);
RwTexture* GetFirstTexture(RwTexDictionary* txd);
RpHAnimHierarchy* GetAnimHierarchyFromSkinClump(RpClump* clump);
RpHAnimHierarchy* GetAnimHierarchyFromFrame(RwFrame* frame);
RpHAnimHierarchy* GetAnimHierarchyFromClump(RpClump* clump);
RpAtomic* AtomicRemoveAnimFromSkinCB(RpAtomic* atomic, void* data);
bool RpAtomicConvertGeometryToTL(RpAtomic* atomic);
bool RpAtomicConvertGeometryToTS(RpAtomic* atomic);
bool RpClumpConvertGeometryToTL(RpClump* clump);
bool RpClumpConvertGeometryToTS(RpClump* clump);
RpMaterial* forceLinearFilteringMatTexturesCB(RpMaterial* material, void* data);
bool SetFilterModeOnAtomicsTextures(RpAtomic* atomic, RwTextureFilterMode filtering);
RpAtomic* forceLinearFilteringAtomicsCB(RpAtomic* atomic, void* data);
bool SetFilterModeOnClumpsTextures(RpClump* clump, RwTextureFilterMode filtering);
bool RpGeometryReplaceOldMaterialWithNewMaterial(RpGeometry* geometry, RpMaterial* oldMaterial, RpMaterial* newMaterial);
RwTexture* RwTexDictionaryFindHashNamedTexture(RwTexDictionary* txd, unsigned int hash);
RpClump* RpClumpGetBoundingSphere(RpClump* clump, RwSphere* bound, bool arg2);
void SkinGetBonePositions(RpClump* clump);
void SkinSetBonePositions(RpClump* clump);
void SkinGetBonePositionsToTable(RpClump* clump, RwV3d* table);
void SetLightsWithTimeOfDayColour(RpWorld* world);
// dummy function
void LightsEnable(int arg0);
RpWorld* LightsDestroy(RpWorld* world);
// lighting = [0.0f;1.0f]
void WorldReplaceNormalLightsWithScorched(RpWorld* world, float lighting);
void WorldReplaceScorchedLightsWithNormal(RpWorld* world);
void AddAnExtraDirectionalLight(RpWorld* world, float x, float y, float z, float red, float green, float blue);
void RemoveExtraDirectionalLights(RpWorld* world);
// lighting = [0.0f;1.0f]
void SetAmbientAndDirectionalColours(float lighting);
// lighting = [0.0f;1.0f]
void SetFlashyColours(float lighting);
// lighting = [0.0f;1.0f]
void SetFlashyColours_Mild(float lighting);
// lighting = [0.0f;1.0f], unused
void SetBrightMarkerColours(float lighting);
void ReSetAmbientAndDirectionalColours();
void DeActivateDirectional();
void ActivateDirectional();
void SetAmbientColoursToIndicateRoadGroup(int arg0);
void SetFullAmbient();
void SetAmbientColours();
void SetAmbientColours(RwRGBAReal* color);
void SetDirectionalColours(RwRGBAReal* color);
// lighting = [0.0f;1.0f]
void SetLightColoursForPedsCarsAndObjects(float lighting);
void SetLightsForInfraredVisionHeatObjects();
void StoreAndSetLightsForInfraredVisionHeatObjects();
void RestoreLightsForInfraredVisionHeatObjects();
void SetLightsForInfraredVisionDefaultObjects();
void SetLightsForNightVision();
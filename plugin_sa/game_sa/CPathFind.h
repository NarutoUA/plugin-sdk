/*
    Plugin-SDK (Grand Theft Auto) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/
#pragma once

#include "plbase/PluginBase_SA.h"
#include "CompressedVector.h"
#include "CVector.h"

#define NUM_PATH_AREAS 72

#pragma pack(push, 1)

class PLUGIN_API CForbiddenArea
{
	float x1, x2, y1, y2, z1, z2;
	bool bEnable;
	unsigned char type;
	char _padding[2];
};

VALIDATE_SIZE(CForbiddenArea, 0x1C);


class PLUGIN_API CNodeAddress
{
public:
    short m_wAreaId;
    short m_wNodeId;

    CNodeAddress() : m_wAreaId(-1), m_wNodeId(-1) {}
};

VALIDATE_SIZE(CNodeAddress, 0x4);


class PLUGIN_API CCarPathLinkAddress
{
public:
    short m_wCarPathLinkId : 10;
    short m_wAreaId : 6;
};

VALIDATE_SIZE(CCarPathLinkAddress, 0x2);


class PLUGIN_API CPathIntersectionInfo
{
public:
    unsigned char m_bRoadCross : 1;
    unsigned char m_bPedTrafficLight : 1;
};

VALIDATE_SIZE(CPathIntersectionInfo, 0x1);


class PLUGIN_API CCarPathLink
{
public:
    struct Position {
        short x;
        short y;
    } m_posn;
    CNodeAddress m_address;
    char m_nDirX;
    char m_nDirY;
    unsigned int m_nPathNodeWidth : 8;

    unsigned int m_nNumLeftLanes : 3;
    unsigned int m_nNumRightLanes : 3;
    unsigned int m_bTrafficLightDirection : 1; // 1 if the navi node has the same direction as the traffic light and 0 if the navi node points somewhere else
    unsigned int unk1 : 1;

    unsigned int m_nTrafficLightState : 2; // 1 - North-South, 2 - West-East cycle
    unsigned int m_bTrainCrossing : 1;
};

VALIDATE_SIZE(CCarPathLink, 0xE);


class PLUGIN_API CPathNode
{
public:
    void *ptr;
	void *ptr2;
    CompressedVector m_posn;
    unsigned short m_wSearchList; // search list id
    short  m_wBaseLinkId;
    short  m_wAreaId;
    short  m_wNodeId;
    unsigned char m_nPathWidth;
    unsigned char m_nFloodFill;

    unsigned int m_nNumLinks : 4;
    unsigned int m_nTrafficLevel : 2;
    unsigned int m_bRoadBlocks : 1;
    unsigned int m_bWaterNode : 1;

    unsigned int m_bEmergencyVehiclesOnly : 1;
    unsigned int unk1 : 1;   // not used in paths data files
    unsigned int m_bDontWander : 1;
    unsigned int unk2 : 1;   // not used in paths data files
    unsigned int m_bNotHighway : 1;
    unsigned int m_bHighway : 1;
    unsigned int unk3 : 1;	 // not used in paths data files
    unsigned int unk4 : 1;	 // not used in paths data files

    unsigned int m_nSpawnProbability : 4;
    unsigned int m_nBehaviourType : 4; // 1 - roadblock
                                       // 2 - parking node

	CVector GetNodeCoors();
};

VALIDATE_SIZE(CPathNode, 0x1C);


class PLUGIN_API CPathFind
{
public:
	CNodeAddress info;
	CPathNode *m_apNodesSearchLists[512];
	CPathNode *m_pPathNodes[NUM_PATH_AREAS];
	CCarPathLink *m_pNaviNodes[NUM_PATH_AREAS];
	CNodeAddress *m_pNodeLinks[NUM_PATH_AREAS];
	unsigned char *m_pLinkLengths[NUM_PATH_AREAS];
	CPathIntersectionInfo *m_pPathIntersections[NUM_PATH_AREAS];
	CCarPathLinkAddress *pNaviLinks[NUM_PATH_AREAS];
	char field_EC4[224];
	unsigned int m_dwNumNodes[NUM_PATH_AREAS];
	unsigned int m_dwNumVehicleNodes[NUM_PATH_AREAS];
	unsigned int m_dwNumPedNodes[NUM_PATH_AREAS];
	unsigned int m_dwNumCarPathLinks[NUM_PATH_AREAS];
	unsigned int m_dwNumAddresses[NUM_PATH_AREAS];
	int field_1544[2048];
	unsigned int m_dwTotalNumNodesInSearchList;
	CNodeAddress char3548[8];
	unsigned int m_dwNumForbiddenAreas;
	CForbiddenArea m_aForbiddenAreas[64];
	bool m_bForbiddenForScriptedCarsEnabled;
	char _padding[3];
	float m_fForbiddenForScrCarsX1;
	float m_fForbiddenForScrCarsX2;
	float m_fForbiddenForScrCarsY1;
	float m_fForbiddenForScrCarsY2;

	//

	void DoPathSearch(unsigned char pathType, CVector origin, CNodeAddress originAddr, 
		CVector target, CNodeAddress *pResultNodes, short *pNodesCount, int maxNodesToFind, float *pDistance, 
		float maxSearchDistance, CNodeAddress *targetAddr, float maxUnkLimit, bool oneSideOnly, 
		CNodeAddress forbiddenNodeAddr, bool includeNodesWithoutLinks, bool waterPath);

	CPathNode *GetPathNode(CNodeAddress address);
};

VALIDATE_SIZE(CPathFind, 0x3C80);

#pragma pack(pop)

extern PLUGIN_API CPathFind& ThePaths;
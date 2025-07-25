#ifndef _ROLLER_LOADTRAK_H
#define _ROLLER_LOADTRAK_H
//-------------------------------------------------------------------------------------------------
#include "types.h"
#include <stdio.h>
//-------------------------------------------------------------------------------------------------

typedef struct
{
  int16 nForwardExtraStart;
  uint8 byForwardMainChunks;
  uint8 byForwardExtraChunks;
  int16 nBackwardExtraStart;
  uint8 byBackwardMainChunks;
  uint8 byBackwardExtraChunks;
} tTrakView;

//-------------------------------------------------------------------------------------------------

typedef struct
{
  tVec3 center;
  int iUnk1;
  int iUnk2;
  int iUnk3;
  int iLeftSurfaceType;
  int iRightSurfaceType;
  float fUnk6;
} tTrackInfo;

//-------------------------------------------------------------------------------------------------

extern uint8 TrackSelect;
extern char *delims;
extern tTrakView TrakView[500];
extern int cur_laps[6];
extern uint8 fp_buf[512];
extern uint8 *start_f;
extern int meof;
extern tTrackInfo TrackInfo[500];
extern float cur_TrackZ;
extern int TRAK_LEN;

//-------------------------------------------------------------------------------------------------

void loadtrack(int iTrackIdx, int a2);
void read_backs(uint8 **ppTrackData);
void read_texturemap(uint8 **ppTrackData);
void read_bldmap(uint8 **ppTrackData);
void readstuntdata(uint8 **pTrackData);
void activatestunts();
void ReadAnimData(FILE *pFile, uint8 **ppFileData);
void readline(FILE *pFile, const char *szFmt, ...);
uint8 *memgets(uint8 *dst, uint8 **ppSrc);
void readline2(uint8 **ppFileData, const char *pszFormat, ...);
void rotatepoint(double dX, double dY, double dZ, double dYaw, double dPitch, double dRoll, double *pdOutX, double *pdOutY, double *pdOutZ);
void setpoint(int iChunkIdx, int iPointIdx, double dX, double dY, double dZ);
void setgpoint(int iChunkIdx, int iPointIdx, double dX, double dY, double dZ);
void resetcars();
void min_skip_stuff(uint8 **ppFileData);

//-------------------------------------------------------------------------------------------------
#endif
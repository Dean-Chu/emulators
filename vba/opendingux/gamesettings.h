/****************************************************************************
 * Visual Boy Advance GX
 *
 * Tantric October 2008
 *
 * gamesettings.h
 *
 * VBA support code
 ***************************************************************************/

#ifndef GAMESETTINGS_H
#define GAMESETTINGS_H

#include "shared.h"

struct gameSetting {
	char gameName[100];
	char gameID[5];
	int saveType;
	int rtcEnabled;
	int flashSize;
	int mirroringEnabled;
};

extern gameSetting gameSettings[];
extern int gameSettingsCount;

struct gamePalette {
	char gameName[17];
	char use;
	u32 palette[14]; // in 24-bit 0xRRGGBB
};

extern gamePalette gamePalettes[];
extern int gamePalettesCount;
extern gamePalette CurrentPalette;

#endif

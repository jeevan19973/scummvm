/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef ADL_ADL_V2_H
#define ADL_ADL_V2_H

#include "adl/adl.h"

// Note: this version of ADL redraws only when necessary, but
// this is not currently implemented.

#define IDI_CUR_ROOM 0xfc
#define IDI_VOID_ROOM 0xfd

namespace Common{
class RandomSource;
}

namespace Adl {

class AdlEngine_v2 : public AdlEngine {
public:
	virtual ~AdlEngine_v2();

protected:
	AdlEngine_v2(OSystem *syst, const AdlGameDescription *gd);

	// AdlEngine
	virtual void setupOpcodeTables();
	bool matchesCurrentPic(byte pic) const;
	byte roomArg(byte room) const;
	void advanceClock();

	void checkTextOverflow(char c);
	void printString(const Common::String &str);

	int o2_isFirstTime(ScriptEnv &e);
	int o2_isRandomGT(ScriptEnv &e);
	int o2_isNounNotInRoom(ScriptEnv &e);
	int o2_isCarryingSomething(ScriptEnv &e);

	int o2_moveItem(ScriptEnv &e);
	int o2_moveAllItems(ScriptEnv &e);
	int o2_placeItem(ScriptEnv &e);
	int o2_tellTime(ScriptEnv &e);
	int o2_setRoomFromVar(ScriptEnv &e);
	int o2_initDisk(ScriptEnv &e);

	struct {
		Common::String time;
	} _strings_v2;

	uint _linesPrinted;

private:
	Common::RandomSource *_random;
};

} // End of namespace Adl

#endif
/****************************************************************************!
*                            _                                               *
*                           / \                         _                    *
*                   ___    / _ \   _ __ ___   ____  ___| |                   *
*                  / _ \  / /_\ \ | '_ ` _ \./  _ \/  _  |                   *
*                 |  __/ /  ___  \| | | | | |  (_) ) (_) |                   *
*                  \___|/__/   \__\_| |_| |_|\____/\_____/                   *
*                                                                            *
*                            eAmod Source File                               *
*                                                                            *
******************************************************************************
* src/map/achievement.h                                                      *
******************************************************************************
* Copyright (c) eAmod Dev Team                                               *
* Copyright (c) rAthena Dev Team                                             *
* Copyright (c) brAthena Dev Team                                            *
* Copyright (c) Hercules Dev Team                                            *
* Copyright (c) 3CeAM Dev Team                                               *
* Copyright (c) Athena Dev Teams                                             *
*                                                                            *
* Licensed under GNU GPL                                                     *
* For more information read the LICENSE file in the root of the emulator     *
*****************************************************************************/

#ifndef _ACHIEVEMENT_H_
#define _ACHIEVEMENT_H_

#include "../common/mmo.h"

#define ACHIEVEMENT_NAME_LENGTH 32
#define ACHIEVEMENT_CUTIN_LENGTH 64 // Taken from clif.c the max size of the image name.

enum AchievementType_Zeny {
	ATZ_HAVE,
	ATZ_USE_SHOP,
	ATZ_GET_VENDING,
	ATZ_USE_VENDING,
	ATZ_USE_SKILL,
};

enum AchievementType_BG {
// Global
	ATB_VICTORY,
	ATB_DEFEAT,
	ATB_LEADER_VICTORY,
	ATB_LEADER_DEFEAT,
// Tierra EoS
	ATB_EOS_FLAGS,
	ATB_EOS_BASES,
	ATB_EOS_VICTORY,
// Tierra Bossnia
	ATB_BOSS_KILLS,
	ATB_BOSS_FLAGS,
	ATB_BOSS_VICTORY,
// Tierra Domination
	ATB_DOM_BASES,
	ATB_DOM_OFFKILLS,
	ATB_DOM_DEFKILLS,
	ATB_DOM_VICTORY,
// Flavius CTF
	ATB_CTF_TAKE,
	ATB_CTF_CAPTURED,
	ATB_CTF_DROP,
	ATB_CTF_VICTORY,
// Flavius TDM
	ATB_TDM_KILLS,
	ATB_TDM_DEATHS,
	ATB_TDM_VICTORY,
// Flavius SC
	ATB_SC_TAKE,
	ATB_SC_CAPTURED,
	ATB_SC_DROP,
	ATB_SC_VICTORY,
// Triple Inferno
	ATB_TI_SKULLS,
	ATB_TI_VICTORY,
// Conquest
	ATB_CON_EMPERIUM,
	ATB_CON_BARRICADE,
	ATB_CON_GSTONE,
	ATB_CON_VICTORY,
// Rush
	ATB_RU_CAPTURE,
	ATB_RU_VICTORY,
};

enum AchievementType {
	AT_SCRIPT,
// Map Exploration
	AT_EXPLORE,
// Monsters Achievements
	AT_MOB_KILL_CLASS,
	AT_MOB_KILL_RACE,
	AT_MOB_KILL_ELEM,
	AT_MOB_KILL_SIZE,
	AT_MOB_CASTLE,
// Player Killing
	AT_PC_KILL,
	AT_PC_DAMAGE_DONE,
// By Getting objectives
	AT_QUEST,
	AT_ACHIEVEMENT,
// Zeny n' Items
	AT_ZENY,			// AchievementType_Zeny
	AT_ITEM_FIND,
	AT_ITEM_HAVE,
	AT_ITEM_EQUIP,
	AT_ITEM_USE,
	AT_ITEM_CONSUME,
// Battleground
	AT_BATTLEGROUND,	// AchievementType_BG
// Limit control
	AT_MAX
};

struct achievement_objetive {
	int value;
	int count;
};

struct achievement_data {
	int id;
	char name[ACHIEVEMENT_NAME_LENGTH];
	char cutin[ACHIEVEMENT_CUTIN_LENGTH];
	int bexp, jexp, nameid, objectives;

	enum AchievementType type;
	struct achievement_objetive ao[ACHIEVEMENT_OBJETIVE_MAX];
};

struct achievement_data* achievement_search(int id);
int achievement_index(struct map_session_data* sd, int id);
void achievement_complete(struct map_session_data* sd, struct achievement_data* ad);
void achievement_validate_explore(struct map_session_data* sd, int mapid);
void achievement_validate_mob(struct map_session_data* sd, int mob_id);
void achievement_validate_killer(struct map_session_data* sd);
void achievement_validate_damage(struct map_session_data* sd, int damage);
void achievement_validate_quest(struct map_session_data* sd, int quest_id);
void achievement_validate_achievement(struct map_session_data* sd, int achievement_id);
void achievement_validate_zeny(struct map_session_data* sd, enum AchievementType_Zeny sub_type, int amount);
void achievement_validate_item(struct map_session_data* sd, enum AchievementType type, int nameid, int amount);
void achievement_validate_bg(struct map_session_data* sd, enum AchievementType_BG sub_type, int amount);
void achievement_db_load(bool clear);

void do_init_achievement(void);
void do_final_achievement(void);

#endif /* _ACHIEVEMENT_H_ */

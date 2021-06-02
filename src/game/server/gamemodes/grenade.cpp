#include "grenade.h"
#include <engine/shared/config.h>
#include <game/server/entities/character.h>
#include <game/server/gamecontext.h>

CGameControllerGCTF::CGameControllerGCTF(class CGameContext *pGameServer) : CGameControllerCTF(pGameServer)
{
	m_pGameType = "gCTF+";
	m_GameFlags = GAMEFLAG_TEAMS|GAMEFLAG_FLAGS;
}

void CGameControllerGCTF::OnCharacterSpawn(CCharacter* pChr)
{
	pChr->IncreaseHealth(10);
	pChr->GiveWeapon(WEAPON_GRENADE, g_Config.m_SvGrenadeAmmo);
}

void CGameControllerGCTF::Tick()
{
	CGameControllerCTF::Tick();
}
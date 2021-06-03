#ifndef GAME_SERVER_DISCORD_BOT_H
#define GAME_SERVER_DISCORD_BOT_H

#include <game/server/gamecontext.h>
#include <dpp/dpp.h>

class CDiscordBot {
public:
	CDiscordBot(CGameContext* pGS) {};
private:
	CGameContext* m_pGS;

};

#endif // !GAME_SERVER_DISCORD_BOT_H
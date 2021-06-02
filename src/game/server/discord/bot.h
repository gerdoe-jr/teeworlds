#ifndef GAME_SERVER_DISCORD_BOT_H
#define GAME_SERVER_DISCORD_BOT_H

#include <game/server/gamecontext.h>
#include <dpp/dpp.h>

class CDiscordBot
{
public:
	std::string Token;
    CDiscordBot(CGameContext *GameServer, std::string Token, dpp::snowflake Channel);
    void LogChat(int Team, std::string Nickname, std::string Message);
    void LogEnter(std::string Nickname);
    void LogExit(std::string Nickname);
private:
    dpp::snowflake m_Channel;
    dpp::cluster *m_Bot = nullptr;
};

#endif
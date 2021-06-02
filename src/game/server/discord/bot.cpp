/* # Discord # */
#include "bot.h"

CGameContext *CGS;

CDiscordBot::CDiscordBot(CGameContext *GameServer, std::string Token, dpp::snowflake Channel)
{
    CGS = GameServer;
    dpp::cluster bot(Token);
    m_Bot = &bot;
    m_Channel = Channel;

    bot.on_ready([&bot](const dpp::ready_t & event)
    {
        char aBuf[256];
        str_format(aBuf, sizeof(aBuf), "Logged in as ", bot.me.username);
        CGS->Console()->Print(1,"Discord", aBuf);
    });

    bot.start(true);
}

void CDiscordBot::LogChat(int Team, std::string Nickname, std::string Message)
{
	std::string aBuf;

    if (Team == TEAM_RED)
    {
        aBuf = "**[RED] " + Nickname + "**: " + Message;
        m_Bot->message_create(dpp::message(m_Channel, aBuf));
    }
    else if (Team == TEAM_BLUE)
    {
        aBuf = "**[BLUE] " + Nickname + "**: " + Message;
        m_Bot->message_create(dpp::message(m_Channel, aBuf));
    }
    else if (Team == TEAM_SPECTATORS)
    {
        aBuf = "**[SPEC] " + Nickname + "**: " + Message;
        m_Bot->message_create(dpp::message(m_Channel, aBuf));
    }
    else
    {
        aBuf = "**" + Nickname + "**: " + Message;
        m_Bot->message_create(dpp::message(m_Channel, aBuf));
    }
}

void CDiscordBot::LogEnter(std::string Nickname)
{
	std::string aBuf;
    if(!m_Channel || !m_Bot)
        return;
    aBuf = "`##` **" + Nickname + "** has entered the game. `##`";
    m_Bot->message_create(dpp::message(m_Channel, aBuf));
}

void CDiscordBot::LogExit(std::string Nickname)
{
    std::string aBuf;
    if(!m_Channel || !m_Bot)
        return;
    aBuf = "`##` **" + Nickname + "** has left the game. `##`";
    m_Bot->message_create(dpp::message(m_Channel, aBuf));
}
/* # Discord # */
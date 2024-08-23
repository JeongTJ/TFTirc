 #ifndef COMMAND_HPP
# define COMMAND_HPP
# include "Server.hpp"

# define RPL_WELCOME				"001"
# define RPL_TOPIC					"332"
# define RPL_NAMREPLY				"353"
# define RPL_ENDOFNAMES				"366"
# define ERR_NOSUCHNICK				"401"
# define ERR_NOSUCHCHANNEL			"403"
# define RPL_TOPIC					"332"
# define RPL_INVITING				"341"
# define RPL_NAMREPLY				"353"
# define RPL_ENDOFNAMES				"366"
# define ERR_CANNOTSENDTOCHAN		"404"
# define ERR_NOTEXTTOSEND			"412"
# define ERR_UNKNOWNCOMMAND			"421"
# define ERR_NONICKNAMEGIVEN		"431"
# define ERR_ERRONEUSNICKNAME		"432"
# define ERR_NICKNAMEINUSE			"433"
# define ERR_NOTONCHANNEL			"442"
# define ERR_USERONCHANNEL			"443"
# define ERR_NOTREGISTERED			"451"
# define ERR_NEEDMOREPARAMS			"461"
# define ERR_ALREADYREGISTERED		"462"
# define ERR_PASSWDMISMATCH			"464"
# define ERR_BADCHANNELKEY			"475"
# define ERR_CHANNELISFULL			"471"
# define ERR_UNKNOWNMODE			"472"
# define ERR_INVITEONLYCHAN			"473"
# define ERR_BADCHANMASK			"476"
# define ERR_CHANOPRIVSNEEDED		"482"

using namespace std;

class Server;
class Client;
class Channel;

class Command {
	public:
		Command();
		Command(const Command& other);
		Command& operator=(const Command& other);
		virtual ~Command();
		virtual void execute(Server& server, Client& client) = 0;
		void setCmdSource(vector<string>& cmdSource);
	protected:
		int checkNotRegisterClient(Server& server, Client& client);
		const string makeNumericMsg(Server& server, Client& client, const string& num);
		const string makeNumericMsg(Server& server, Client& client, const string& name, const string& num);
		const string makeNumericMsg(Server& server, Client& client, Channel& channel, const string& num);
		vector<string> _cmdSource;
};

#endif
#ifndef SERVER_HPP
# define SERVER_HPP

#include <set>
#include <map>
#include <string>
#include <fstream>
#include <utility>
#include <vector>


#include "../host/Host.hpp"
#include "../client/Client.hpp"

#include "../sockets/ServerSockt.hpp"

namespace ft
{
	class Server
	{
		friend class Nginy;
		friend class Client;
		//================================================================================================
		//	attributes
		//================================================================================================
		private:
			ServerSockt				_sockt;
			std::vector<Host *>		_hosts;
			std::map<int, Client *>	_clients;
		//================================================================================================
		//	attributes End
		//================================================================================================
		
		
		//================================================================================================
		//	destructors, constructors, and assignment operators
		//================================================================================================
		public:
			Server();
			~Server();

			Server(ServerSockt sockt);

		private:
			Server(const Server& src);
			Server	&operator=(const Server& rop);
		//================================================================================================
		//	destructors, constructors, and assignment operators End
		//================================================================================================


		//================================================================================================
		//	Server operations
		//================================================================================================
		public:
			int	getSocktFd() const;
			std::string	getPortNumber() const;

			void	delClient(Client *client);
		//================================================================================================
		//	Server operations End
		//================================================================================================


		//================================================================================================
		//	private methods
		//================================================================================================
		private:
			void	_deepCopy(const Server& src);
		//================================================================================================
		//	private methods End
		//================================================================================================
	
		//================================================================================================
		//	overload << for Server
		//================================================================================================
		public:
			friend std::ostream	&operator<<(std::ostream& ostr, const Server& server);
		//================================================================================================
		//	overload << for Server End
		//================================================================================================
	};
}

#endif
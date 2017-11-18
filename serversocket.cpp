/*
   Copyright (C) 2017 - 2018 this.mutzii@gmail.com

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/
#include "include/serversocket.h"

using namespace Network::NetSocket;

ServerSocket::ServerSocket(int portNumber)
{
    struct sockaddr_in serv_addr;

    m_server_socket = 0;
    m_server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if( m_server_socket <  0 )
    {
        Logger::instance().error("Error: opening socket");
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons( portNumber );

    if (bind( m_server_socket , (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    {
        Logger::instance().error("Error: Port binding - Port already used? ");
    }
}

ServerSocket::~ServerSocket(){}

int ServerSocket::socketAccept() throw( std::exception )
{
    int newsockfd;
    struct sockaddr_in cli_addr;
    socklen_t clilen;

    listen( m_server_socket , 1);

    clilen = sizeof(cli_addr);

    newsockfd = accept( m_server_socket, (struct sockaddr *) &cli_addr, &clilen);

    if (newsockfd < 0)
            throw ErrorException("Error: on accept");

    return newsockfd;
}

void ServerSocket::destroy_socket( int socket )
{
    close( socket );
}

void ServerSocket::destroy_server()
{
    close( m_server_socket );
}

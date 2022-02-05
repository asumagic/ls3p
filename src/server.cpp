#include <ls3p/server.hpp>

namespace ls3p
{

Server::Server()
{

}

void Server::on_initialize(const structs::general::InitializedParams& params)
{
    m_client_params = params;
}

}
#pragma once

#include <ls3p/structs/common.hpp>
#include <ls3p/structs/general/init.hpp>
#include <ls3p/jsonrpc.hpp>
#include <ls3p/transport.hpp>

namespace ls3p
{

class Server final
{
    public:
    Server();

    private:
    void on_initialize(const structs::general::InitializedParams& params);

    structs::general::InitializedParams m_client_params;
};

}
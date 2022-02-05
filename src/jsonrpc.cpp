#include <ls3p/jsonrpc.hpp>

#include <iostream>

namespace ls3p
{

void HttpJsonRpcServer::run_blocking()
{
    for (;;)
    {
        handle_request();
    }
}

void HttpJsonRpcServer::handle_request()
{
    const auto header = parse_http_header(read_http_header());

    for (const auto& [key, value] : header)
    {
        std::cout << key << ", " << value << '\n';
    }
}

std::string HttpJsonRpcServer::read_http_header()
{
    std::string buffer;

    for (;;)
    {
        std::array<char, 1> ugly_char_buffer;
        m_transport->read(ugly_char_buffer.data(), 1);
        buffer += ugly_char_buffer[0];

        if (buffer.size() >= 4
            && std::string_view(buffer).substr(buffer.size() - 4) == "\r\n\r\n")
        {
            return buffer;
        }
    }
}

std::map<std::string_view, std::string_view> HttpJsonRpcServer::parse_http_header(std::string_view header)
{
    std::map<std::string_view, std::string_view> result;

    auto line_begin_pos = 0;
    auto line_end_pos = header.find("\r\n");

    while (line_end_pos != header.npos)
    {
        const std::string_view line(
            header.data() + line_begin_pos,
            line_end_pos - line_begin_pos
        );

        const auto separator_pos = line.find(": ");
        
        if (separator_pos != line.npos)
        {
            result.emplace(std::make_pair(
                line.substr(0, separator_pos),
                line.substr(separator_pos + 2)
            ));
        }

        line_begin_pos = line_end_pos + 2;
        line_end_pos = header.find("\r\n", line_begin_pos);
    }

    return result;
}

}
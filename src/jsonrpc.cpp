#include <ls3p/jsonrpc.hpp>

#include <ls3p/structs/base/message.hpp>

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
    const auto header_buffer = read_http_header();
    const auto header_params = parse_http_header(header_buffer);
    
    const auto content_length = std::stoi(std::string(header_params.at("Content-Length")));

    std::vector<char> content_buffer(content_length);
    m_transport->read(content_buffer.data(), content_length);

    const auto content_json = nlohmann::json::parse(content_buffer.begin(), content_buffer.end());
    parse_json_content(content_json);
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

}
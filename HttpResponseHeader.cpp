#include "HttpResponseHeader.h"

#include <regex>

long HttpResponseHeader::length()
{
    m_strStream.seekg(0, std::ios::end);

    auto size = m_strStream.tellg();

    if (size < 0) {
        size = 0;
    }

    m_strStream.seekg(0, std::ios::beg);
    
    return static_cast<long>(size);
}

int HttpResponseHeader::parse()
{
    m_strStream.seekg(0, std::ios::beg);

    std::string requestLine;
    if (std::getline(m_strStream, requestLine)) {
        std::istringstream iss(requestLine);
        std::string method;
        std::string uri;
        std::string httpVersion;

        iss >> httpVersion;
        iss >> m_statusCode;

        std::regex format_http1(R"(HTTP/1.[0-1])");
        if (regex_match(httpVersion, format_http1)) {
            auto pos = httpVersion.find("0");
            if (pos == std::string::npos) {
                m_httpVersion = HttpVersion::version_1_1;
            }
            else {
                m_httpVersion = HttpVersion::version_1_0;
            }
        } else if (httpVersion == R"(HTTP/2.0)") {
            m_httpVersion = HttpVersion::version_2_0;
        }
        else {
            return -1;
        }
    }
    else {
        return -2;
    }

    return 0;
}

#pragma once

#include<iostream>
#include<sstream>
#include<string>

class HttpResponseHeader
{
public:
	enum class HttpVersion
	{
		unknown,
		version_1_0,
		version_1_1,
		version_2_0,
	};
public:
	HttpResponseHeader(std::stringstream &ss)
	{
		m_strStream << ss.rdbuf();
	}

	int parse();

	long length();
	int statusCode() const { return m_statusCode; };
	std::string uri() const { return m_uri; };
	HttpVersion httpVersion() const { return m_httpVersion; }

private:

	std::stringstream m_strStream;

	int m_statusCode = 0;

	std::string m_method;
	std::string m_uri;
	HttpVersion m_httpVersion = HttpVersion::unknown;
};


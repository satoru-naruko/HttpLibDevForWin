#include "gtest/gtest.h"
#include "HttpResponseHeader.h"

TEST(HttpResponseHeader_Parse, HTTP1_0) {
	std::stringstream ss;

	ss << R"(HTTP/1.0)" << ' ' << 200 << ' ' << "OK" << std::endl;

	HttpResponseHeader respHeader(ss);
	int ret = respHeader.parse();

	ASSERT_EQ(0, ret);
	ASSERT_EQ(HttpResponseHeader::HttpVersion::version_1_0, respHeader.httpVersion());
	ASSERT_EQ(200, respHeader.statusCode());
}

TEST(HttpResponseHeader_Parse, HTTP1_1) {
	std::stringstream ss;

	ss << R"(HTTP/1.1)" << ' ' << 200 << ' ' << "OK" << std::endl;

	HttpResponseHeader respHeader(ss);
	int ret = respHeader.parse();

	ASSERT_EQ(0, ret);
	ASSERT_EQ(HttpResponseHeader::HttpVersion::version_1_1, respHeader.httpVersion());
	ASSERT_EQ(200, respHeader.statusCode());
}
#include "pch.h"
#include "HttpResponseHeader.h"

// sample
TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(HttpResponseHeader_Parse, Get) {
	std::stringstream ss;

	ss << R"(HTTP/1.0)" << ' ' << 200 << ' ' << "OK" << std::endl;

	HttpResponseHeader respHeader(ss);
	int ret = respHeader.parse();

	ASSERT_EQ(0, ret);
}
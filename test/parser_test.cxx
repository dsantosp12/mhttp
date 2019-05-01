#include <array>
#include <string>
#include <algorithm>
#include <gtest/gtest.h>

#include "parser.h"
#include "common.h"
#include "request.h"

using namespace jtp;

class MParserTest : public testing::Test
{
protected:
    std::string jtpRequest = "{" \
                                    "\"method\":\"GET\"," \
                                    "\"uri\": \"/accounts/1234\"," \
                                    "\"version\": \"1.1\"," \
                                    "\"headers\": { " \
                                        "\"Host\":\"127.0.0.1:9999\"," \
                                        "\"Connection\":\"keep-alive\"," \
                                        "\"User-Agent\":\"Mozilla/5.0 (Macintosh; Intel Mac OS X 10_14_0) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/67.0.3396.99 Safari/537.36\"," \
                                        "\"Accept\":\"text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8\"," \
                                        "\"Accept-Language\":\"en-US,en;q=0.9,es;q=0.8\"" \
                                    "},"\
                                    "\"body\": \"\"" \
                              "}";

};

TEST_F(MParserTest, ParserJTPGet)
{
    MRequest request;
    MParser parser;
    parser.parse(jtpRequest, &request);

    EXPECT_EQ(request._method, GET);
    EXPECT_EQ(request._uri, "/accounts/1234");
    EXPECT_EQ(request._version, "1.1");
    EXPECT_EQ(request._headers.get("Host"), "127.0.0.1:9999");
    EXPECT_EQ(request._headers.get("Connection"), "keep-alive");
    EXPECT_EQ(request._headers.get("Accept"), "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8");
    EXPECT_EQ(request._headers.get("User-Agent"), "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_14_0) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/67.0.3396.99 Safari/537.36");
    EXPECT_EQ(request._headers.get("Accept-Language"), "en-US,en;q=0.9,es;q=0.8");
    EXPECT_EQ(request._body, "");
}

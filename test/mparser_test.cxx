// #include <array>
// #include <string>
// #include <algorithm>
// #include <gtest/gtest.h>

// #include "../src/mhttp/mparser.h"
// #include "../src/mhttp/mcommon.h"

// class MParserTest : public testing::Test {
//   protected:
//     std::string goodRequest = "GsdfT / HTTP/1.1\r\n" \
//                             "Host: 127.0.0.1:9999\r\n" \
//                             "Connection: keep-alive\r\n" \
//                             "User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_14_0) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/67.0.3396.99 Safari/537.36\r\n" \
//                             "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8\r\n" \
//                             "Accept-Language: en-US,en;q=0.9,es;q=0.8\r\n\r\n";
// };

// TEST_F(MParserTest, GetMethodWithCorrectRequest) {

//   std::array<char, 8192> buff;
//   std::copy(goodRequest.begin(), goodRequest.end(), buff.begin());

//   mhttp::MParser parser;
//   auto method = parser.getMethod(buff);

//   ASSERT_NE(method, mhttp::MOptString(std::nullopt));

//   EXPECT_EQ(*method, "GET");
// }

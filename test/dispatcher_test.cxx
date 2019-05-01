#include <gtest/gtest.h>
#include "dispatcher.h"
#include "../src/json/json.hpp"

using namespace jtp;

TEST(MDispatcher_Test, DispatchRequest)
{
    json data;
    data["method"] = "POST";
    data["uri"] = "/accounts/123";
    data["version"] = "1.1";
    data["headers"]["Host"] = "127.0.0.1:9999";
    data["headers"]["Connection"] = "keep-alive";
    data["body"] = "{ \"id\": 123 }";


    MBuffer buff;
    std::string rawRequest = data.dump();
    std::copy(rawRequest.begin(), rawRequest.end(), buff.begin());

    MDispatcher disp;
    auto resp = disp.dispatch(buff);

    EXPECT_EQ(resp._method, POST);
}
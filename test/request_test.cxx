#include <iostream>
#include "gtest/gtest.h"
#include "request.h"
#include "../src/json/json.hpp"

using namespace jtp;

TEST(MRequest_Test, DeserializeRequest)
{
    MRequest req;
    req._method = GET;
    req._uri = "/accounts/123";
    req._version = "1.1";

    req._headers.set("Host", "127.0.0.1:9999");
    req._headers.set("Connection", "keep-alive");

    req._body = "{ \"id\": 123 }";

    json outBuff;

    req.deserialize(&outBuff);

    EXPECT_EQ(outBuff["method"], "GET");
    EXPECT_EQ(outBuff["uri"], req._uri);
    EXPECT_EQ(outBuff["version"], req._version);
    EXPECT_EQ(outBuff["body"], req._body);
    
    // Note: order isn't deterministic
    EXPECT_EQ(outBuff["headers"]["Connection"], req._headers.get("Connection"));
    EXPECT_EQ(outBuff["headers"]["Host"], req._headers.get("Host"));
}

TEST(MRequest_Test, SerializeRequest)
{
    json data;
    data["method"] = "POST";
    data["uri"] = "/accounts/123";
    data["version"] = "1.1";
    data["headers"]["Host"] = "127.0.0.1:9999";
    data["headers"]["Connection"] = "keep-alive";
    data["body"] = "{ \"id\": 123 }";

    MRequest req;
    req.serialize(data);

    EXPECT_EQ(req._method, POST);
    EXPECT_EQ(req._uri, data["uri"]);
    EXPECT_EQ(req._version, data["version"]);
    EXPECT_EQ(req._body, data["body"]);
    EXPECT_EQ(req._headers.get("Connection"), data["headers"]["Connection"]);
    EXPECT_EQ(req._headers.get("Host"), data["headers"]["Host"]);
}
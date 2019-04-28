#include <gtest/gtest.h>
#include "mcommon.h"

using namespace mhttp;

TEST(MCommon_Test, methodToString) {
    EXPECT_EQ(MmethodToStr(GET), "GET");
    EXPECT_EQ(MmethodToStr(POST), "POST");
    EXPECT_EQ(MmethodToStr(PUT), "PUT");
    EXPECT_EQ(MmethodToStr(DELETE), "DELETE");
    EXPECT_THROW(MmethodToStr(UNKNOWN), std::invalid_argument);
}

TEST(MCommon_Test, stringToMethod) {
    EXPECT_EQ(MstrToMethod("GET"), GET);
    EXPECT_EQ(MstrToMethod("POST"), POST);
    EXPECT_EQ(MstrToMethod("PUT"), PUT);
    EXPECT_EQ(MstrToMethod("DELETE"), DELETE);
    EXPECT_EQ(MstrToMethod("TEST"), UNKNOWN);
}

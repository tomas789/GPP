#include "gtest/gtest.h"

#include <cstring>
#include <string>

#include "Exception.hpp"

TEST(Exception, Exception) {
    const char * someText = "The rain in Spain stays mainly in the plain";
    auto e1 = GPP::Exception();
    ASSERT_EQ(nullptr, e1.what());

    auto e2 = GPP::Exception(std::string(someText));
    ASSERT_STREQ(someText, e2.what());

    auto e3 = GPP::Exception(someText);
    ASSERT_STREQ(someText, e3.what());

    auto e4 = GPP::Exception((const char *)nullptr);
    ASSERT_EQ(nullptr, e4.what());
}


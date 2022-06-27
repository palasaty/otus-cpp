#include <iostream>
#include "gtest/gtest.h"
#include "ip.h"

TEST(dummy, test1)
{
    EXPECT_EQ(1, 1);
}

TEST(ip, create)
{
    Ip ip{"10.22.33.11 "};
    EXPECT_TRUE(ip.equal(IpBytes{10, 22, 33, 11}));
}
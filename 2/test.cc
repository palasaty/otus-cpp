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

TEST(ip, failCreateAbc)
{
    EXPECT_ANY_THROW(Ip{"a.b.c"});
}

TEST(ip, failCreateShort)
{
    EXPECT_ANY_THROW(Ip{"12"});
}

TEST(ip, failCreateMixed)
{
    EXPECT_ANY_THROW(Ip{"12.a.x"});
}

TEST(ip, failCreateLong)
{
    EXPECT_ANY_THROW(Ip{"12.5.4.5.7"});
}

TEST(ip, checkExceptionNonSymbol)
{
    try {
        Ip ip{"a"};
    } catch(std::exception& e) {
        EXPECT_STREQ(e.what(), "Exception while parsing 'a': Non-number symbols");
    }
}

TEST(ip, checkExceptionNon4Parts)
{
    try {
        Ip ip{"1.2"};
    } catch(std::exception& e) {
        EXPECT_STREQ(e.what(), "Exception while parsing '1.2': Ip address should have 4 parts");
    }
}

TEST(ips, sort) {
    IpContainer ips;
    ips.add("1.2.3.4");
    ips.add("1.10.1.1");

    testing::internal::CaptureStdout();
    ips.sort();
    ips.print();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "1.10.1.1\n1.2.3.4\n");
}

TEST(ips, equal4670) {
    IpContainer ips;
    ips.add("1.2.3.4");
    ips.add("46.70.1.1");

    testing::internal::CaptureStdout();
    ips.print_equal(IpBytes{46,70});
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "46.70.1.1\n");   
}

TEST(ips, equalAny) {
    IpContainer ips;
    ips.add("1.46.3.4");
    ips.add("46.70.1.1");
    ips.add("1.1.46.9");
    ips.add("46.46.46.46");
    ips.add("1.1.1.46");

    ips.sort();

    testing::internal::CaptureStdout();
    ips.print_equal_any(46);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "46.70.1.1\n46.46.46.46\n1.46.3.4\n1.1.46.9\n1.1.1.46\n");   
}
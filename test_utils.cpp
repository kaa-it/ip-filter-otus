//
// Created by --- on 31.07.2023.
//

#include <gtest/gtest.h>

#include "utils.h"

TEST(TestSplitSuite, TestEmptyWithDotDelemiter)
{
    std::string value;
    char d = '.';

    auto res = split(value, d);

    EXPECT_TRUE(res.size() == 1);
    EXPECT_TRUE(res[0].empty());
}

TEST(TestSplitSuite, TestNotEmptyWithoutDelemiter)
{
    std::string value{"11"};
    char d = '.';

    auto res = split(value, d);

    EXPECT_TRUE(res.size() == 1);
    EXPECT_TRUE(res[0] == value);
}

TEST(TestSplitSuite, TestNotEmptyWithOnlyDelemiter)
{
    std::string value{".."};
    char d = '.';

    auto res = split(value, d);

    EXPECT_TRUE(res.size() == 3);
    EXPECT_TRUE(res[0].empty());
    EXPECT_TRUE(res[1].empty());
    EXPECT_TRUE(res[2].empty());
}

TEST(TestSplitSuite, TestNotEmptyWithOneDelemiterAtEnd)
{
    std::string value{"11."};
    char d = '.';

    auto res = split(value, d);

    EXPECT_TRUE(res.size() == 2);
    EXPECT_TRUE(res[0] == "11");
    EXPECT_TRUE(res[1].empty());
}

TEST(TestSplitSuite, TestNotEmptyWithOneDelemiterAtStart)
{
    std::string value{".11"};
    char d = '.';

    auto res = split(value, d);

    EXPECT_TRUE(res.size() == 2);
    EXPECT_TRUE(res[0].empty());
    EXPECT_TRUE(res[1] == "11");
}

TEST(TestSplitSuite, TestNotEmptyWithOneDelemiterAtCenter)
{
    std::string value{"11.22"};
    char d = '.';

    auto res = split(value, d);

    EXPECT_TRUE(res.size() == 2);
    EXPECT_TRUE(res[0] == "11");
    EXPECT_TRUE(res[1] == "22");
}

// ================

TEST(TestJoinSuite, TestEmptyWithDotDelemiter)
{
    std::vector<std::string> value;
    char d = '.';

    auto res = join(value, d);

    EXPECT_TRUE(res.empty());
}

TEST(TestSplitSuite, TestNotEmptyWithTwoEmptyElements)
{
    std::vector<std::string> value{"", ""};
    char d = '.';

    auto res = join(value, d);

    EXPECT_TRUE(res.empty());
}

TEST(TestJoinSuite, TestNotEmptyWithDotDelemiter) {
    std::vector<std::string> value{"11"};
    char d = '.';

    auto res = join(value, d);

    EXPECT_TRUE(res == "11");
}

TEST(TestJoinSuite, TestTwoElementsWithDelemiter)
{
    std::vector<std::string> value{"11", "12"};
    char d = '.';

    auto res = join(value, d);

    EXPECT_TRUE(res == "11.12");
}


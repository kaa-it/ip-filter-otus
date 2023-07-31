#include "lib.h"

#include <gtest/gtest.h>

TEST(TestVersionSuite, TestVersion)
{
	EXPECT_TRUE(version() > 0);
}

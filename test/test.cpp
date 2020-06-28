#include <fstream>
#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "parse.h"
#include "textFunctions.h"

#define TEXT "test/test-Text.txt"
#define RESULT "test/test-Result.txt"

std::string text;
std::vector<std::string> words;

TEST(checkPathTest, correct)
{
    EXPECT_TRUE(checkPath(TEXT));
    EXPECT_TRUE(checkPath(RESULT));
}
TEST(checkPathTest, incorrect)
{
	EXPECT_FALSE(checkPath(" "));
	EXPECT_FALSE(checkPath("test/TEXT.txt"));
}
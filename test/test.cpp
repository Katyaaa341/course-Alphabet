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
TEST(getTextTest, correct)
{
    words.clear();
    EXPECT_TRUE(getText(text, TEXT));
}
TEST(writeResultsTest, correct)
{
    words.clear();

    getText(text, TEXT);
    parse(text, words);
    EXPECT_TRUE(writeResults(words, RESULT));

    std::ofstream file(RESULT, std::ios_base::trunc);
}

TEST(writeResultsTest, incorrect)
{
    words.clear();

    getText(text, TEXT);
    parse(text, words);
    EXPECT_FALSE(writeResults(words, "test/RESULT.txt"));

    std::ofstream file(RESULT, std::ios_base::trunc);
}
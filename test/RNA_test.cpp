#include <gtest/gtest.h>

#include "../RNA.h"
#include "../InvalidCharacter.h"

using namespace Alphabet;

TEST(RNA, toCharacter)
{
ASSERT_NO_THROW(RNA::toCharacter('A'));
ASSERT_NO_THROW(RNA::toCharacter('U'));
ASSERT_NO_THROW(RNA::toCharacter('G'));
ASSERT_NO_THROW(RNA::toCharacter('C'));

EXPECT_EQ(RNA::Characters::A, RNA::toCharacter('A'));
EXPECT_EQ(RNA::Characters::U, RNA::toCharacter('U'));
EXPECT_EQ(RNA::Characters::G, RNA::toCharacter('G'));
EXPECT_EQ(RNA::Characters::C, RNA::toCharacter('C'));

EXPECT_THROW(RNA::toCharacter('i'), InvalidCharacter);
EXPECT_THROW(RNA::toCharacter('\0'), InvalidCharacter);
EXPECT_THROW(RNA::toCharacter(' '), InvalidCharacter);
EXPECT_THROW(RNA::toCharacter('8'), InvalidCharacter);
EXPECT_THROW(RNA::toCharacter('L'), InvalidCharacter);
EXPECT_THROW(RNA::toCharacter('q'), InvalidCharacter);
}

TEST(RNA, toChar)
{
EXPECT_EQ('A', RNA::toChar(RNA::Characters::A));
EXPECT_EQ('U', RNA::toChar(RNA::Characters::U));
EXPECT_EQ('G', RNA::toChar(RNA::Characters::G));
EXPECT_EQ('C', RNA::toChar(RNA::Characters::C));
}
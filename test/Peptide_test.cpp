#include <gtest/gtest.h>

#include "../Peptide.h"
#include "../InvalidCharacter.h"

using namespace Alphabet;

TEST(Peptide, toCharacter)
{
ASSERT_NO_THROW(Peptide::toCharacter('A'));
ASSERT_NO_THROW(Peptide::toCharacter('B'));
ASSERT_NO_THROW(Peptide::toCharacter('C'));
ASSERT_NO_THROW(Peptide::toCharacter('D'));
ASSERT_NO_THROW(Peptide::toCharacter('E'));
ASSERT_NO_THROW(Peptide::toCharacter('F'));
ASSERT_NO_THROW(Peptide::toCharacter('G'));
ASSERT_NO_THROW(Peptide::toCharacter('H'));
ASSERT_NO_THROW(Peptide::toCharacter('I'));
ASSERT_NO_THROW(Peptide::toCharacter('J'));
ASSERT_NO_THROW(Peptide::toCharacter('K'));
ASSERT_NO_THROW(Peptide::toCharacter('L'));
ASSERT_NO_THROW(Peptide::toCharacter('M'));
ASSERT_NO_THROW(Peptide::toCharacter('N'));
ASSERT_NO_THROW(Peptide::toCharacter('O'));
ASSERT_NO_THROW(Peptide::toCharacter('P'));
ASSERT_NO_THROW(Peptide::toCharacter('Q'));
ASSERT_NO_THROW(Peptide::toCharacter('R'));
ASSERT_NO_THROW(Peptide::toCharacter('S'));
ASSERT_NO_THROW(Peptide::toCharacter('T'));


EXPECT_EQ(Peptide::Characters::Ala, Peptide::toCharacter('A'));
EXPECT_EQ(Peptide::Characters::Arg, Peptide::toCharacter('B'));
EXPECT_EQ(Peptide::Characters::Asn, Peptide::toCharacter('C'));
EXPECT_EQ(Peptide::Characters::Asp, Peptide::toCharacter('D'));
EXPECT_EQ(Peptide::Characters::Cys, Peptide::toCharacter('E'));
EXPECT_EQ(Peptide::Characters::Gln, Peptide::toCharacter('F'));
EXPECT_EQ(Peptide::Characters::Glu, Peptide::toCharacter('G'));
EXPECT_EQ(Peptide::Characters::Gly, Peptide::toCharacter('H'));
EXPECT_EQ(Peptide::Characters::His, Peptide::toCharacter('I'));
EXPECT_EQ(Peptide::Characters::Ile, Peptide::toCharacter('J'));
EXPECT_EQ(Peptide::Characters::Leu, Peptide::toCharacter('K'));
EXPECT_EQ(Peptide::Characters::Lys, Peptide::toCharacter('L'));
EXPECT_EQ(Peptide::Characters::Met, Peptide::toCharacter('M'));
EXPECT_EQ(Peptide::Characters::Phe, Peptide::toCharacter('N'));
EXPECT_EQ(Peptide::Characters::Pro, Peptide::toCharacter('O'));
EXPECT_EQ(Peptide::Characters::Ser, Peptide::toCharacter('P'));
EXPECT_EQ(Peptide::Characters::Thr, Peptide::toCharacter('Q'));
EXPECT_EQ(Peptide::Characters::Trp, Peptide::toCharacter('R'));
EXPECT_EQ(Peptide::Characters::Tyr, Peptide::toCharacter('S'));
EXPECT_EQ(Peptide::Characters::Val, Peptide::toCharacter('T'));


EXPECT_THROW(Peptide::toCharacter('j'), InvalidCharacter);
EXPECT_THROW(Peptide::toCharacter('\0'), InvalidCharacter);
EXPECT_THROW(Peptide::toCharacter(' '), InvalidCharacter);
EXPECT_THROW(Peptide::toCharacter('5'), InvalidCharacter);
EXPECT_THROW(Peptide::toCharacter('X'), InvalidCharacter);
EXPECT_THROW(Peptide::toCharacter('v'), InvalidCharacter);

}

TEST(Peptide, toChar)
{
EXPECT_EQ('A', Peptide::toChar(Peptide::Characters::Ala));
EXPECT_EQ('B', Peptide::toChar(Peptide::Characters::Arg));
EXPECT_EQ('C', Peptide::toChar(Peptide::Characters::Asn));
EXPECT_EQ('D', Peptide::toChar(Peptide::Characters::Asp));
EXPECT_EQ('E', Peptide::toChar(Peptide::Characters::Cys));
EXPECT_EQ('F', Peptide::toChar(Peptide::Characters::Gln));
EXPECT_EQ('G', Peptide::toChar(Peptide::Characters::Glu));
EXPECT_EQ('H', Peptide::toChar(Peptide::Characters::Gly));
EXPECT_EQ('I', Peptide::toChar(Peptide::Characters::His));
EXPECT_EQ('J', Peptide::toChar(Peptide::Characters::Ile));
EXPECT_EQ('K', Peptide::toChar(Peptide::Characters::Leu));
EXPECT_EQ('L', Peptide::toChar(Peptide::Characters::Lys));
EXPECT_EQ('M', Peptide::toChar(Peptide::Characters::Met));
EXPECT_EQ('N', Peptide::toChar(Peptide::Characters::Phe));
EXPECT_EQ('O', Peptide::toChar(Peptide::Characters::Pro));
EXPECT_EQ('P', Peptide::toChar(Peptide::Characters::Ser));
EXPECT_EQ('Q', Peptide::toChar(Peptide::Characters::Thr));
EXPECT_EQ('R', Peptide::toChar(Peptide::Characters::Trp));
EXPECT_EQ('S', Peptide::toChar(Peptide::Characters::Tyr));
EXPECT_EQ('T', Peptide::toChar(Peptide::Characters::Val));

}
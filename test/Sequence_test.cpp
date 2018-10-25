#include <gtest/gtest.h>

#include "../Sequence.h"
#include "../DNA.h"
#include "../InvalidCharacter.h"

using namespace Alphabet;

TEST(Sequence, fromString)
{
const std::string& str = "AGTCAGTC";
EXPECT_EQ(Sequence<"AGTCAGTC">, Sequence<Alpha>::fromString(str));
ASSERT_NO_THROW(Sequence<DNA>::fromString("AGTGTT"));
ASSERT_NO_THROW(Sequence<DNA>::fromString("CCAGTCA"));
ASSERT_NO_THROW(Sequence<DNA>::fromString("AAATTCGATA"));
}

TEST(Sequence, toString)
{
Sequence<DNA> seq = Sequence<DNA>::fromString("AGTC");
EXPECT_EQ("AGTC", seq->toString());
}

TEST(Sequence, size)
{
Sequence<DNA> seq = Sequence<DNA>::fromString("AGTC");
EXPECT_EQ(4, seq->size());
}

TEST(Sequence, clear)
{
    // TODO: Implement
}

TEST(Sequence, resize)
{
Sequence<DNA> seq = Sequence<DNA>::fromString("AGTC");
EXPECT_EQ(5, seq->resize(5)->size());
EXPECT_EQ(3, seq->resize(3)->size());
}

TEST(Sequence, reserve)
{
    // TODO: Implement
}

TEST(Sequence, push_back)
{
Sequence<DNA> seq = Sequence<DNA>::fromString("AGTC");
size_t i = seq->size();

EXPECT_EQ(i+1, seq->push_back(DNA::Characters::A)->size());
}

TEST(Sequence, get_setComment)
{
Sequence<DNA> seq = Sequence<DNA>::fromString("AGTC");
seq->setComment("gene1");
EXPECT_EQ("gene1", seq->getComment());
}

TEST(Sequence, compare)
{
Sequence<DNA> seq1 = Sequence<DNA>::fromString("AGTC");
const Sequence<DNA> seq2 = Sequence<DNA>::fromString("AGTC");
size_t i = 2

EXPECT_EQ(true, seq->compare(seq2, i));
}

TEST(Sequence, overlap)
{
 // TODO: Implement
}

TEST(Sequence, statistics)
{
// TODO: Implement
}

TEST(Sequence, operator1)
{
// TODO: Implement
}

TEST(Sequence, operator_unequal)
{
// TODO: Implement
}

TEST(Sequence, operator_equal)
{
// TODO: Implement
}

TEST(Sequence, operator_output)
{
// TODO: Implement
}

TEST(Sequence, operator_input)
{
// TODO: Implement
}


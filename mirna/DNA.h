#ifndef MIRNA_DNA_H
#define MIRNA_DNA_H

namespace Alphabet
{
    class DNA
    {
    public:
        /// The characters available for DNA
        enum class Characters {
            a, // Adenine intron
            A, // Adenine exon
            t, // Thymine intron
            T, // Thymine exon
            g, // Guanine intron
            G, // Guanine exon
            c, // Cytosine intron
            C, // Cytosine exon
            N  // Unknown. Valid characters are 'N' and 'n'.
        };

        /**
         * Converts a char to a Character, case sensitive.
         * @throw InvalidCharacter exception if the passed char is invalid.
         */
        static Characters toCharacter(char c);

        /**
         * Converts a Character to an upper-case char.
         */
        static char toChar(Characters c);
    };
}





#endif //MIRNA_DNA_H

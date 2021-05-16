#ifndef MIRNA_RNA_H
#define MIRNA_RNA_H

namespace Alphabet
{

    class RNA
    {
    public:
        /// The characters available for RNA
        enum class Characters { A, U, G, C };

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

#endif //MIRNA_RNA_H

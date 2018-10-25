#include <iostream>
#include "RNA.h"
#include "InvalidCharacter.h"

namespace Alphabet
{
    RNA::Characters RNA::toCharacter(char c) {

        switch (c) {

            case 'A' : return RNA::Characters::A;
            case 'U' : return RNA::Characters::U;
            case 'G' : return RNA::Characters::G;
            case 'C' : return RNA::Characters::C;
            default : throw InvalidCharacter(c);
        }
    }

    char RNA::toChar(Characters c) {

        switch (c) {

            case RNA::Characters::A : return 'A';
            case RNA::Characters::U : return 'U';
            case RNA::Characters::G : return 'G';
            case RNA::Characters::C : return 'C';
            default : std::cerr << "Invalid RNA Character!" << std::endl;
        }

        return 'N';
    }
}


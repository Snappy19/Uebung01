#include "DNA.h"
#include "InvalidCharacter.h"

#include <iostream>

namespace Alphabet
{
    DNA::Characters DNA::toCharacter(char c)
    {
        switch (c) {

            case 'a' : return DNA::Characters::a;
            case 'A' : return DNA::Characters::A;
            case 't' : return DNA::Characters::t;
            case 'T' : return DNA::Characters::T;
            case 'g' : return DNA::Characters::g;
            case 'G' : return DNA::Characters::G;
            case 'c' : return DNA::Characters::c;
            case 'C' : return DNA::Characters::C;
            case 'N' : return DNA::Characters::N;
            case 'n' : return DNA::Characters::N;
            default : throw InvalidCharacter(c);
        }
    }

    char DNA::toChar(Characters c)
    {
        switch (c) {

            case DNA::Characters::a : return 'A';
            case DNA::Characters::A : return 'A';
            case DNA::Characters::t : return 'T';
            case DNA::Characters::T : return 'T';
            case DNA::Characters::g : return 'G';
            case DNA::Characters::G : return 'G';
            case DNA::Characters::c : return 'C';
            case DNA::Characters::C : return 'C';
            case DNA::Characters::N : return 'N';
            default : std::cerr << "Invalid DNA Character!" << std::endl;
        }
        return 'N';
    }
}
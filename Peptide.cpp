#include <iostream>
#include "Peptide.h"
#include "InvalidCharacter.h"

namespace Alphabet
{
    Peptide::Characters Peptide::toCharacter(char c) {

        switch (c) {

            case 'A' : return Peptide::Characters::Ala;
            case 'B' : return Peptide::Characters::Arg;
            case 'C' : return Peptide::Characters::Asn;
            case 'D' : return Peptide::Characters::Asp;
            case 'E' : return Peptide::Characters::Cys;
            case 'F' : return Peptide::Characters::Gln;
            case 'G' : return Peptide::Characters::Glu;
            case 'H' : return Peptide::Characters::Gly;
            case 'I' : return Peptide::Characters::His;
            case 'J' : return Peptide::Characters::Ile;
            case 'K' : return Peptide::Characters::Leu;
            case 'L' : return Peptide::Characters::Lys;
            case 'M' : return Peptide::Characters::Met;
            case 'N' : return Peptide::Characters::Phe;
            case 'O' : return Peptide::Characters::Pro;
            case 'P' : return Peptide::Characters::Ser;
            case 'Q' : return Peptide::Characters::Thr;
            case 'R' : return Peptide::Characters::Trp;
            case 'S' : return Peptide::Characters::Tyr;
            case 'T' : return Peptide::Characters::Val;
            default : throw InvalidCharacter(c);

        }
    }

    char Peptide::toChar(Characters c) {

        switch (c) {

            case Peptide::Characters::Ala: return 'A';
            case Peptide::Characters::Arg: return 'B';
            case Peptide::Characters::Asn: return 'C';
            case Peptide::Characters::Asp: return 'D';
            case Peptide::Characters::Cys: return 'E';
            case Peptide::Characters::Gln: return 'F';
            case Peptide::Characters::Glu: return 'G';
            case Peptide::Characters::Gly: return 'H';
            case Peptide::Characters::His: return 'I';
            case Peptide::Characters::Ile: return 'J';
            case Peptide::Characters::Leu: return 'K';
            case Peptide::Characters::Lys: return 'L';
            case Peptide::Characters::Met: return 'M';
            case Peptide::Characters::Phe: return 'N';
            case Peptide::Characters::Pro: return 'O';
            case Peptide::Characters::Ser: return 'P';
            case Peptide::Characters::Thr: return 'Q';
            case Peptide::Characters::Trp: return 'R';
            case Peptide::Characters::Tyr: return 'S';
            case Peptide::Characters::Val: return 'T';
            default : std::cerr << "Invlaid Characters!" << std::endl;
        }
        return 'N';

    }

}


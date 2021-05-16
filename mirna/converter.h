#ifndef MIRNA_CONVERTER_H
#define MIRNA_CONVERTER_H

#include "json.hpp"
#include "InvalidCharacter.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * converter class
 *
 * performs several conversions/translations on a RNA/DNA sequence
 *
 */


class converter{

private:

    string seq;         // sequence subject to change
    string ori_seq;     // original sequence, gets set when initialized, does not change!

public:

    /**
     * Basic constructor
     * @param sequence The sequence to convert/translate, also gets saved as 'ori_seq'
     */
    explicit converter(string& sequence);
    converter() = default;

    /**
     * Sets seq to given sequence
     * @param sequence
     */
    void setSeq(string& sequence);

    /**
     * either gets new sequence after changing it or the original sequence
     * @return seq/ori_seq
     */
    string getSeq();
    string getOriSeq();

    // evtl hier als argument nochmal converter übergeben


    /**
     * generates the complementary RNA strand to given RNA sequence
     */
    void complementary_RNA();

    /**
     * generates the complementary DNA strand to given DNA sequence
     */
    void complementary_DNA();

    /**
     * converts given RNA sequence into DNA sequence
     */
    void convert_to_DNA();

    /**
     * converts given DNA sequence into RNA sequence
     */
    void convert_to_RNA();

};

#endif //MIRNA_CONVERTER_H

converter::converter(string &sequence) {
    this->seq = sequence;
    this->ori_seq = sequence;
}

void converter::setSeq(string& sequence) {
    this->seq = sequence;
}

string converter::getOriSeq() {
    return this->ori_seq;
}

string converter::getSeq() {
    return this->seq;
}

void converter::complementary_RNA() {

    string origin_seq = this->seq;
    string complementary_seq(origin_seq.length(), ' ');

    for (int i = 0; i < origin_seq.length(); ++i){
       if (origin_seq[i] == 'A'){
           complementary_seq[i] = 'U';
       }
       else if (origin_seq[i] == 'C'){
            complementary_seq[i] = 'G';
       }
       else if (origin_seq[i] == 'G'){
            complementary_seq[i] = 'C';
       }
       else if (origin_seq[i] == 'U'){
            complementary_seq[i] = 'A';
       }
       else if (origin_seq[i] == 'N'){
            complementary_seq[i] = 'N';
       }
       else {
           throw InvalidCharacter(origin_seq[i]);
       }
    }

/*
    for(char c : origin_seq){
        switch(c){
            case 'A' : complementary_seq += 'U';
            case 'C' : complementary_seq += 'G';
            case 'G' : complementary_seq += 'C';
            case 'U' : complementary_seq += 'A';
            case 'N' : complementary_seq += 'N';
            default : throw InvalidCharacter(c);
        }
    }
*/

    this->seq = complementary_seq;
}

void converter::complementary_DNA() {

    string origin_seq = this->seq;
    string complementary_seq(origin_seq.length(), ' ');

    for (int i = 0; i < origin_seq.length(); ++i){
        if (origin_seq[i] == 'A'){
            complementary_seq[i] = 'T';
        }
        else if (origin_seq[i] == 'C'){
            complementary_seq[i] = 'G';
        }
        else if (origin_seq[i] == 'G'){
            complementary_seq[i] = 'C';
        }
        else if (origin_seq[i] == 'T'){
            complementary_seq[i] = 'A';
        }
        else if (origin_seq[i] == 'N'){
            complementary_seq[i] = 'N';
        }
        else {
            throw InvalidCharacter(origin_seq[i]);
        }
    }

    this->seq = complementary_seq;
}

void converter::convert_to_DNA() {

    string origin_seq = this->seq;
    string converted_seq(origin_seq.length(), ' ');

    for (int i = 0; i < origin_seq.length(); ++i){
        if (origin_seq[i] == 'A'){
            converted_seq[i] = 'A';
        }
        else if (origin_seq[i] == 'C'){
            converted_seq[i] = 'C';
        }
        else if (origin_seq[i] == 'G'){
            converted_seq[i] = 'G';
        }
        else if (origin_seq[i] == 'U'){
            converted_seq[i] = 'T';
        }
        else if (origin_seq[i] == 'N'){
            converted_seq[i] = 'N';
        }
        else {
            throw InvalidCharacter(origin_seq[i]);
        }
    }
    this->seq = converted_seq;

}

void converter::convert_to_RNA() {

    string origin_seq = this->seq;
    string converted_seq(origin_seq.length(), ' ');

    for (int i = 0; i < origin_seq.length(); ++i){
        if (origin_seq[i] == 'A'){
            converted_seq[i] = 'A';
        }
        else if (origin_seq[i] == 'C'){
            converted_seq[i] = 'C';
        }
        else if (origin_seq[i] == 'G'){
            converted_seq[i] = 'G';
        }
        else if (origin_seq[i] == 'T'){
            converted_seq[i] = 'U';
        }
        else if (origin_seq[i] == 'N'){
            converted_seq[i] = 'N';
        }
        else {
            throw InvalidCharacter(origin_seq[i]);
        }
    }

    this->seq = converted_seq;
}


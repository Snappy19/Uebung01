#include "json.hpp"
#include "InvalidCharacter.h"
#include "miRNA.h"
#include "RNA.h"
#include "DNA.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

miRNA::miRNA(const char *miRNA_file_path) {

    fstream miRNA_file;
    string line;

    miRNA_file.open(miRNA_file_path);

    if(!miRNA_file.is_open()){
        cerr << "Could not open miRNA file!" << endl;
    }

    while (getline(miRNA_file, line)){

        if (line.substr(0,1) == ">"){
            miRNA_ID = line.substr(1, line.find(' '));
        }
        else {
            miRNA_sequence.append(line);
        }
    }

    changed_miRNA_seq = miRNA_sequence;

}


void miRNA::generate_complementary_RNA(){

    string origin_seq = this->changed_miRNA_seq;
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
    changed_miRNA_seq = complementary_seq;
}

void miRNA::generate_complementary_DNA(){

    string origin_seq = this->changed_miRNA_seq;
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
    changed_miRNA_seq = complementary_seq;
}

void miRNA::convert_to_RNA(){

    string origin_seq = this->changed_miRNA_seq;
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
    changed_miRNA_seq = converted_seq;
}

void miRNA::convert_to_DNA(){

    string origin_seq = this->changed_miRNA_seq;
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
    changed_miRNA_seq = converted_seq;
}



/**
 * generic Getter and Setter
 */

const string &miRNA::get_miRNASequence() const {
    return miRNA_sequence;
}

const string &miRNA::get_miRNAId() const {
    return miRNA_ID;
}

string& miRNA::get_changed_miRNASequence() {
    return changed_miRNA_seq;
}

string& miRNA::getToken() {
    return token;
}

/**
 * Catch input errors
 * @param seq
 */
void miRNA::set_miRNASequence(string& seq){

    miRNA_sequence.erase();

    for (int i = 0; i < seq.length(); ++i){
        if (seq[i] == 'A'){
            miRNA_sequence[i] = 'A';
        }
        else if (seq[i] == 'C'){
            miRNA_sequence[i] = 'C';
        }
        else if (seq[i] == 'G'){
            miRNA_sequence[i] = 'G';
        }
        else if (seq[i] == 'U'){
            miRNA_sequence[i] = 'U';
        }
        else if (seq[i] == 'N'){
            miRNA_sequence[i] = 'N';
        }
        else {
            throw InvalidCharacter(seq[i]);
        }
    }
}

void miRNA::set_miRNAId(string& id){
    miRNA_ID = id;
}

void miRNA::set_changed_miRNASequence(string &seq) {
    changed_miRNA_seq = seq;
}

void miRNA::set_miRNAToken(size_t token_size) {

    if (token_size > changed_miRNA_seq.length() || token_size < 1){
        cerr << "token_size must be in range of miRNA_sequence size!" << endl;
    }
    else {
        // Will always be in range of seed region
        token = changed_miRNA_seq.substr(1, token_size);
    }
}
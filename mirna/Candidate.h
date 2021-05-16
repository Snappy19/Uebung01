#ifndef MIRNA_CANDIDATE_H
#define MIRNA_CANDIDATE_H

#include "json.hpp"

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class Candidate{

private:

    size_t can_start;
    size_t can_end;
    string can_seq;
    string can_chr_id;

public:

    Candidate(size_t start, size_t end, string& seq, string& chr_id);

    size_t getStart(Candidate& c);
    size_t getEnd(Candidate& c);
    string getSeq(Candidate& c);
    string getChrID(Candidate& c);

    void setStart(size_t var);
    void setEnd(size_t var);
    void setSeq(string& var_seq);
    void setChrID(string& chr_id);

};


#endif //MIRNA_CANDIDATE_H


Candidate::Candidate(size_t start, size_t end, string& seq, string& chr_id) {
    can_start = start;
    can_end = end;
    can_seq = seq;
    can_chr_id = chr_id;
}

size_t Candidate::getStart(Candidate& c) {
    return c.can_start;
}
size_t Candidate::getEnd(Candidate& c) {
    return c.can_end;
}

std::string Candidate::getSeq(Candidate& c) {
    return c.can_seq;
}

string Candidate::getChrID(Candidate &c) {
    return c.can_chr_id;
}

void Candidate::setStart(size_t var) {
    can_start = var;
}

void Candidate::setEnd(size_t var) {
    can_end = var;
}

void Candidate::setSeq(string &var_seq) {
    can_seq = var_seq;
}

void Candidate::setChrID(string &chr_id) {
    can_chr_id = chr_id;
}
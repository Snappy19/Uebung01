#ifndef MIRNA_CHROMOSOME_H
#define MIRNA_CHROMOSOME_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class Chromosome{

private:
    string chromosome_id;
    string chromosome_seq;

public:
    Chromosome(string& chr_id, string& chr_seq){
        this->chromosome_id = chr_id;
        this->chromosome_seq = chr_seq;
    }

    string getChromosomeID(){return this->chromosome_id;}
    string getChromosomeSeq(){return this->chromosome_seq;}

    void setChromosomeID(string& chr_id){this->chromosome_id = chr_id;}
    void setChromosomeSeq(string& chr_seq){this->chromosome_seq = chr_seq;}

};

#endif //MIRNA_CHROMOSOME_H

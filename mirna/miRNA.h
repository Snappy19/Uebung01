#ifndef MIRNA_MIRNA_H
#define MIRNA_MIRNA_H

#include "json.hpp"
#include "InvalidCharacter.h"
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

class miRNA{

private:

    string miRNA_sequence;      // original sequence
    string changed_miRNA_seq;   // sequence subject to change
    string miRNA_ID;

    string token;

public:

  explicit miRNA(const char* miRNA_file_path);

    const string &get_miRNASequence() const;
    const string &get_miRNAId() const;
    string& get_changed_miRNASequence();
    string& getToken();


    void set_miRNASequence(string& seq);
    void set_miRNAId(string& id);
    void set_changed_miRNASequence(string& seq);

    void generate_complementary_RNA();
    void generate_complementary_DNA();
    void convert_to_RNA();
    void convert_to_DNA();

    void set_miRNAToken(size_t token_size);

};

#endif //MIRNA_MIRNA_H
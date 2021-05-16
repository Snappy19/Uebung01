#include "Chromosome.h"
#include "GenomeProcessor.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>
#include <regex>

using namespace std;

GenomeProcessor::GenomeProcessor(const char *genome_file_path) {
    this->genome_file_path = genome_file_path;
}

void GenomeProcessor::other_organism() {

    fstream genome_file;
    string line;
    string org;
    string chr_id;
    string sequence;

    size_t count = 1;

    bool first_found = true;
    bool chr_to_create = false;

    genome_file.open(genome_file_path);

    if(!genome_file.is_open()){
        cerr << "Could not open genome file!" << endl;
        exit(EXIT_FAILURE);
    }

    while(getline(genome_file, line)){
        if(line.substr(0,1) == ">"){
            if (first_found){
                organism = line.substr(29, 6);  //find first of, find last of
                first_found = false;
            }
            if (chr_to_create){
                Chromosome chr(chr_id, sequence);
                processed_genome.insert(pair<size_t, Chromosome>(count, chr));
                count++;
            }
            chr_id = line.substr(1, line.find(' '));
            chr_to_create = true;
            sequence.clear();
        }
        else {
            sequence.append(line);
        }
    }

    Chromosome chr(chr_id, sequence);
    processed_genome.insert(pair<size_t, Chromosome>(count, chr));

}

void GenomeProcessor::human() {

}
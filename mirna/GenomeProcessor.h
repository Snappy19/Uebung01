#ifndef MIRNA_GENOMEPROCESSOR_H
#define MIRNA_GENOMEPROCESSOR_H

#include "Chromosome.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>
#include <regex>

using namespace std;


/**
 * Erstelle vllt 2 genomeProcessor
 * 1) HumanGenome
 * 2) Genome
 *
 * ist vielleicht besser/einfacher, aber guck ertsmal hiermit :)
 */

class GenomeProcessor{

private:

    string organism;
    const char* genome_file_path;
    map<size_t, Chromosome> processed_genome;

public:

    explicit GenomeProcessor(const char* genome_file_path);

    /**
     * Getter and Setter
     */
    string getOrganism(){return this->organism;}
    const char* getFilePath(){return this->genome_file_path;}
    map<size_t, Chromosome> getProcessedGenome(){return this->processed_genome;}
    void setOrganism(string& org){this->organism = org;}
    void setFilePath(const char* file_path){this->genome_file_path = file_path;}
    //void setmap

    /**
     * Processes genome .fa-file based on organism
     *
     * differs between human and all other organism
     * (because the files slighty differ)
     * that way it is easier to go through the files and extract what we need
     */

    void human();
    void other_organism();

};

#endif //MIRNA_GENOMEPROCESSOR_H

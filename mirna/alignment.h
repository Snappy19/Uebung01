#ifndef MIRNA_ALIGNMENT_H
#define MIRNA_ALIGNMENT_H

#include "json.hpp"
#include "InvalidCharacter.h"
#include "Matrix.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>

using json = nlohmann::json;
using namespace std;


class alignment{

private:

    string seq_1;
    string seq_2;

    //scores festlegen?

    size_t g_c, a_u, g_u, a_t;
    size_t penalty;
    size_t gap_open_pen, gap_ext_pen;
    size_t threshold;
    float scaling_factor;

    // INFO: Ich muss beim Algorithmus merken, von wo wir beim
    // füllen der Matrix gekommen sind (für traceback)

public:

    alignment() = default;

    alignment(string& seq1, string& seq2, const char* json_path);

    /**
     * several get and set functions (generic)
     */
     void setSeq1(string& seq){ this->seq_1 = seq;}
     void setSeq2(string& seq){ this->seq_2 = seq;}
     void setThreshold(size_t thresh){ this->threshold = thresh;}
     void setScalingFactor(float scal_f){ this->scaling_factor = scal_f;}
     void setPenalties(size_t penalty_score, size_t gap_open_penalty, size_t gap_ext_penalty){
        this->penalty = penalty_score; this->gap_open_pen = gap_open_penalty; this->gap_ext_pen = gap_ext_penalty;
     }
     void setComplementScores(size_t g_c_score, size_t a_u_score, size_t g_u_score, size_t a_t_score){
        this->g_c = g_c_score; this->a_u = a_u_score; this->g_u = g_u_score; this->a_t= a_t_score;
     }

     string getSeq1(){return this->seq_1;}
     string getSeq2(){return this->seq_2;}
     size_t getGC(){return this->g_c;}
     size_t getAU(){return this->a_u;}
     size_t getGU(){return this->g_u;}
     size_t getAT(){return this->a_t;}
     size_t getPenalty(){return this->penalty;}
     size_t getGapOpenPen(){return this->gap_open_pen;}
     size_t getGapExtPen(){return this->gap_ext_pen;}
     size_t getThreshold(){return this->threshold;}
     float getScalingFactor(){return this->scaling_factor;}

     template <class T>
     Matrix<T> generateMatrix(){
         size_t rows = this->seq_1.size();
         size_t cols = this->seq_2.size();
         Matrix mat = Matrix(rows,cols,0.0);
         return mat;
     }

     /**
      * alignment algorithm (Smith-Waterman)
      */

};

#endif //MIRNA_ALIGNMENT_H


/**
 * json helper function, used to read the parameters from json file
 */
json readParameters(const char* path)
{
    std::ifstream istrm(path);

    if(!istrm) {
        std::cerr << "Could not open file " << path << " for reading.\n";

        // Call exit here to avoid complicated error handling. Only use this
        // method in the main file as it makes program abortion unrecoverable
        // and hard to predict.
        std::exit(-2);
    }

    try {
        json parameters;
        istrm >> parameters;

        return parameters;
    } catch(const std::invalid_argument& e) {
        std::cerr << "Error while parsing config file: " << e.what() << '\n';
    }

    // See above
    std::exit(-3);
}


alignment::alignment(string &seq1, string &seq2, const char* json_path) {
     this->seq_1 = seq1;
     this->seq_2 = seq2;
     auto parameters = readParameters(json_path);
     this->g_c = parameters["g_c"];
     this->a_u = parameters["a_u"];
     this->g_u = parameters["g_u"];
     this->a_t = parameters["a_t"];
     this->penalty = parameters["penalty"];
     this->gap_open_pen = parameters["gap_open_pen"];
     this->gap_ext_pen = parameters["gape_ext_pen"];
     this->threshold = parameters["threshold"];
     this->scaling_factor = parameters["scaling_factor"];
}


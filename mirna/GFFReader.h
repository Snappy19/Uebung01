#ifndef MIRNA_GFFREADER_H
#define MIRNA_GFFREADER_H

#include "json.hpp"

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <queue>

using namespace std;
class GFFReader
{
public:

    /**
     * constructor
     */
    GFFReader(const char* path);

   int getChrId(const char* path);



private:

    /// path to .gff-file that was passed on
    const char* gff_file;

};

#endif //MIRNA_GFFREADER_H

#include "json.hpp"
#include "GFFReader.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <queue>

using namespace std;

GFFReader::GFFReader(const char* path) {
   gff_file = path;
}

int GFFReader::getChrId(const char* path){

    return 1;

}
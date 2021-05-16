cmake_minimum_required(VERSION 3.14)
project(mirna)

set(CMAKE_CXX_STANDARD 17)

add_library(SHARED
        json.hpp
        DNA.cpp
        DNA.h
        InvalidCharacter.cpp
        InvalidCharacter.h
        RNA.cpp
        RNA.h
        Sequence.cpp
        Sequence.h)

add_executable(mirna
        main.cpp
        DNA.cpp
        DNA.h
        InvalidCharacter.cpp
        InvalidCharacter.h
        RNA.cpp
        RNA.h
        Sequence.cpp
        Sequence.h
        Candidate.h
        Chromosome.h
        GenomeProcessor.h
        GenomeProcessor.cpp
        alignment.h
        Matrix.h
        miRNA.h
        miRNA.cpp)
cmake_minimum_required(VERSION 3.12)
project(Uebung01)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(test)

add_executable(Uebung01
        2Bit.cpp
        2Bit.h
        CMakeLists.txt
        convert.cpp
        DNA.cpp
        DNA.h
        Fasta.h
        InvalidCharacter.cpp
        InvalidCharacter.h
        ParsingException.cpp
        ParsingException.h
        Peptide.cpp
        Peptide.h
        RNA.cpp
        RNA.h
        Sequence.h test/main_test.cpp test/DNA_test.cpp test/RNA_test.cpp test/Peptide_test.cpp test/Sequence_test.cpp)

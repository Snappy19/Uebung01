#ifndef MIRNA_MATRIX_H
#define MIRNA_MATRIX_H

#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

template<class T>
class Matrix {

private:

    vector<vector<T>> mat;
    size_t rows;
    size_t cols;
    T init_value;

public:
    Matrix() = default;

    /**
     * constructor
     * @param r
     * @param c
     */
    Matrix(size_t r, size_t c, T init_value){
        rows = r;
        cols = c;
        this->init_value = init_value;
        mat.resize(rows);
        for (size_t i = 0; i < mat.size(); i++){
            mat[i].resize(cols, this->init_value);
        }
    }

    /**
     * @return the value from the field inside the matrix
     */
    T & operator()(const size_t & r, const size_t & c){
        return this->mat[r][c];
    }

    /**
     * fills in the given field of the matrix
     * @param value
     */
    void fill (const size_t & r, const size_t & c, T value) {
        this->mat[r][c] = value;
    }

    /**
     * @return amount of rows
     */
    size_t get_rows() const{
        return this->rows;
    }

    /**
     * @return amount of columns
     */
    size_t get_cols() const {
        return this->cols;
    }

    void increment(const size_t & r, const size_t & c) {
        ++(this->mat[r][c]);
    }

    /**
     * @return sum of the values in one specific row
     * */
    T sumRow(const size_t & r) {
        T sum = 0;
        for(size_t c = 0; c < cols; ++c) {
            sum += this->mat[r][c];
        }
        return sum;
    }

    /**
     * @return sum of the values in one specific column
     * */
    T sumCol(const size_t & c) {
        T sum = 0;
        for(size_t r = 0; r < rows; ++r) {
            sum += this->mat[r][c];
        }
        return sum;
    }

    /**
     * @return sum of all values in the matrix
     * */
    T sumTotal () {
        T sum = 0;
        for(size_t r = 0; r < rows; ++r) {
            for(size_t c = 0; c < cols; ++c) {
                sum += this->mat[r][c];
            }
        }
        return sum;
    }

    /**
     * prints the matrix, in this case specifically with the amino acids
     */
    void printMatrix(){
        for(size_t i = 0; i < rows; ++i){
            //std::cout << "AA " << CodeToAminoAcid(i) << ": ";
            for(size_t j = 0; j < cols; ++j){
                //std::cout << std::setfill(' ') << std::setw(10) << this->mat[i][j];
                std::cout << this->mat[i][j] << ",";
            }
            std::cout  << "\n";
        }
        std::cout  << "\n";
    }

};

#endif //MIRNA_MATRIX_H

#ifndef MATRIX_H
#define MATRIX_H


#include <vector>
#include <string>
#include <fstream>
#include <math.h>

class matrix
{
    public:


        // exceprions


        class InvalidIndexException : public std::exception{};
        class OutOfTriangleException : public std::exception{};
        class DimensionMismatchException : public std::exception{};
        class InvalidVectorException : public std::exception{};


        matrix();
        matrix(const std::vector<int> &vec);
        matrix(int size);
        matrix(const std:: string& filename);

    //getters

    int getSize() const {return m_size;}
    int getElement(int i, int j) const;

    //setters

    void setVec(const std:: vector<int> &vec);
    void setElement(int i, int j, int e);


    static matrix add(const matrix& a, const matrix& b);
    static matrix multiply(const matrix &a, const matrix &b);

    friend std::ostream &operator<<(std::ostream &os, const matrix &m);

    //protected:

    private:

        int m_size;
        std::vector<int> m_vec;

        int ind(int i , int j) const;
        double calcSizefromLength(unsigned int length);
        bool inLowerTri(int i, int j) const;



};

#endif // MATRIX_H


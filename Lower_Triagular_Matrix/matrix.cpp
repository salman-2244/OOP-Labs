#include "matrix.h"

matrix::matrix()
{
    m_size = 3;
    m_vec = {1,2,3,4,5,6};
}

matrix::matrix(const std:: vector<int> &vec){

    setVec(vec);

}

matrix::matrix(int size){

    m_size = size;
    m_vec.resize((size *(size +1))/2);

}

matrix::matrix(const std:: string &filename){
std:: fstream f(filename);
if (f.fail()){


    m_size = 0;
    m_vec.clear();
}
else
{

    int e;
    while (f >> e){

        m_vec.push_back(e);
    }
    double n = calcSizefromLength(m_vec.size());
    if (n == floor(n))
    {
        m_size = n;
    }
    else {

        m_size = 0;
        m_vec.clear();

    }
}

}


int matrix::ind(int i, int j) const{

 return j + i*(i-1)/2 -1;

}


double matrix::calcSizefromLength(unsigned int length){

    return (-1+sqrt(1+8 * length)) /2;


}


bool matrix::inLowerTri(int i , int j) const{

    return (1<=j && j<=i && i<=m_size);

}



int matrix::getElement(int i , int j) const{

    if (inLowerTri(i,j)){


        return m_vec[ind(i,j)];

    }
    else if (1<=j && j<=m_size && 1<=i && i<=m_size){

        return 0;
    }


}


void matrix::setVec(const std::vector<int> &vec){

    double n = calcSizefromLength(vec.size());
    if (n == floor(n)){

        m_size = n;
        m_vec = vec;
    }
    else{

        throw InvalidVectorException();
    }
}

void matrix::setElement(int i, int j, int e){

if (1<=j && j<=i && i<=m_size){


    m_vec[ind(i,j)]= e;

}
else  throw OutOfTriangleException();
}

matrix matrix::add(const matrix& a, const matrix& b){

    if (a.getSize() == b.getSize())
    {


        matrix sum(a);
        for (int i=0; i<a.m_vec.size(); i++){

            sum.m_vec[i] += b.m_vec[i];
        }
        return sum;
    }
    else{

        throw DimensionMismatchException();
    }

}


matrix matrix::multiply(const matrix& a, const matrix& b){
    if (a.getSize() == b.getSize())
    {
        matrix mul(a.getSize()); /// creating a matrix filled with 0 of the same size like a
        for (int i=1;i<=a.m_size;i++)
        {
            for (int j=1;j<=a.m_size;j++)
            {
                if (a.inLowerTri(i,j)) /// only the lower triangular part need calculation
                {
                    for (int k=1;k<=a.m_size;k++)
                    {
                        mul.setElement(i,j,mul.getElement(i,j)+a.getElement(i,k)*b.getElement(k,j));
                    }
                }
            }
        }
        return mul;
    }
    else
    {
        throw DimensionMismatchException();
    }
}

std:: ostream &operator<<(std:: ostream &os, const matrix &m){

os << m.m_size <<"x"<<m.m_size<<std::endl;

for(int i=1; i<= m.m_size;i++){

    for(int j=1; j<=m.m_size;j++){


        os<< m.getElement(i,j)<<" ";

    }
    os <<std::endl;
}


return os;
}



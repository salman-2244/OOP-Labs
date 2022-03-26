#include "inFile.h"

inFile::inFile(const std:: string &filename)
{
    _x.open(filename.c_str());
    if(_x.fail()) throw FILE_ERROR;
}

std::ostream &operator<<(std::ostream &os, const Occurance &o)
{
    os<<"Number :" <<o.number <<" , Occurance :" << o.count;

    return os;
}


void inFile:: read()
{

    _x>>_dx;
    if(_x.fail())
    {
        _sx = abnorm;
    }
    else{
        _sx = norm;
    }
}

void inFile::next()
{
    _end = (_sx == abnorm);

    if(!_end)
    {
        //_dx
        _cur.number = _dx;
        _cur.count =0;
        for(; _sx == norm && _cur.number == _dx; read())
        {
            _cur.count++;

        }
    }
}

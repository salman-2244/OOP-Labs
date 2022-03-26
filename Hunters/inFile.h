#ifndef INFILE_H
#define INFILE_H

#include <iostream>
#include <fstream>

struct Occurance {

int number;
int count;

friend std::ostream &operator<<(std::ostream &os, const Occurance &o);
};

enum Status {norm, abnorm};

class inFile
{
    public:
        enum Errors {FILE_ERROR};
        inFile(const std::string &filename);
        ~inFile() {_x.close();}

        void first() { read(); next();}
        void next();
        bool end() const {return _end;}
        Occurance current() {return _cur;}


    private:
        //sx dx x
        Status _sx;
        int _dx;
        std::ifstream _x;

        bool _end;

        Occurance _cur;

        void read();
};

#endif // INFILE_H

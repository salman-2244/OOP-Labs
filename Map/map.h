#ifndef PRIORSOR_H_INCLUDED
#define PRIORSOR_H_INCLUDED
#include <string>
#include <iostream>
#include <vector>
#include "read.hpp"
#include <exception>

using namespace std;
inline bool valid(int a) {return true;}

struct Item {

int key;
string data;



//constructor for Struct
Item(){}

Item(int key, string data) : key(key),data(data){}

friend istream& operator>>(istream& s, Item& e){

e.key = read<int>("key","Integer is needed",valid);

cout<<"Data"<<endl;

s>>e.data;

return s;

}


friend ostream& operator<<(ostream& s, const Item& e){

s<<"("<<e.key<<","<<e.data<<")";

return s;


}

bool operator ==(const Item&b){

return (key == b.key && data == b.data);

}
};

class map
{
    public:
        class ExistingKeyException : public exception {};
        class NonExistingKeyException : public exception {};
        //map();

        int count() const {return _vec.size();}
        void insert(Item a) throw (exception);
        void erase (int key) throw (exception);
        bool isIn(int key) const;

        string &operator[](int key) throw (exception); //didn't understood

        bool isEmpty() const {return _vec.size() ==0;}

        friend ostream& operator<<( ostream& s, const map& m);

        //methods for testing

        vector<Item> getItems() const;
        pair<bool,int> getLogSearch(int key) const {return logSearch(key);}



    private:

        vector <Item> _vec;
        pair<bool,int> logSearch(int key) const;
};

#endif // MAP_H

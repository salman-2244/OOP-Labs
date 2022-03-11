#include "map.h"

using namespace std;


void map::insert(Item e) throw (exception)
{


    pair<bool, int> out = logSearch(e.key);

    if(!out.first){


        _vec.resize(_vec.size()+1);
        for(int i= _vec.size()-2; i>=out.second; i--){

            _vec[i+1]= _vec[i];

        }
        _vec[out.second] = e;

    }
    else
    {

        throw ExistingKeyException();
    }


}

void map:: erase(int key) throw (exception)
{

    pair<bool,int> out = logSearch(key);

    if(out.first)
    {

        for(unsigned int i = out.second+1; i< _vec.size(); i++)
        {

            _vec[i-1] = _vec[i];

        }
        _vec.pop_back();
    }
    else
    {

        throw NonExistingKeyException();
    }
}
    bool map::isIn(int key) const
    {

        return logSearch(key).first;
    }

    string &map::operator[](int key) throw (exception) //did not understand this syntax
    {

        pair<bool,int> out=logSearch(key);

        if(out.first)
        {

            return _vec[out.second].data;

        }

    else
        {

            throw NonExistingKeyException();
        }
    }






pair<bool,int> map:: logSearch(int key) const
{
    bool l = false;
    int lb =0;
    int ub = _vec.size()-1;
    int ind;

    while (!l && lb <= ub){

        ind = (ub+lb)/2;
        if (_vec[ind].key > key){ ub = ind -1;}
        else if (_vec[ind].key < key){ lb = ind +1;}
        else { l = true;}


    }
    if(!l)
    {

        ind = lb;
    }
    return pair<bool,int>(l,ind);
}


ostream& operator<<(ostream& s, const map& m)
{
    s<<"\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
    s<<"Number of elements: "<<m._vec.size()<<"\nContent: "<<endl;
    for(unsigned i=0; i<m._vec.size(); ++i){
        s<<" "<<m._vec[i];///Item e;
    }
    s<<"\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n";
    return s;
}

vector<Item> map::getItems() const
{

    vector<Item> v;
    for(unsigned i =0; i<_vec.size(); ++i)
    {
        v.push_back(_vec[i]);
    }
    return v;
}



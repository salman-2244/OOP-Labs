#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

bool fileSetup (vector<int> &vec, const string filename);
bool CondMaxSearch(vector<int> &x, int & maxi, int &ind);
bool MaxSearchFile(const string filename , int &maxi);
int main()
{
    cout<<"Please Enter the File Name"<<endl;
    string filename;
    cin>>filename;

   vector<int> vect;
   int maxi = 0;
   int ind = 0;

   bool fileExists = fileSetup (vect,filename);

   if (fileExists){

    bool maxSearchWorks = CondMaxSearch(vect,maxi,ind);
    if (maxSearchWorks){

        cout<<"The Maximum Valley is "<<maxi<<" And it is at the Index  " <<ind<<endl;

    }
    else{

        cout<<"Highest Valley  Does Not Exits"<<endl;

    }
    if (MaxSearchFile(filename ,maxi)){

        cout<<"The Maximum Valley from MaxSearchFile is "<<maxi<<endl;
    }
    else{
        cout<<"Highest Valley  Does Not Exits"<<endl;

    }
   }
   else
        cout<<"File Does Not Exist"<<endl;
    return 0;
}
 bool fileSetup (vector<int> &vec, const string filename){

    fstream fileStream(filename);
    if (fileStream.fail()){
        return false;
    }

    int num;
    vec.clear();
    while(fileStream >> num){
        vec.push_back(num);

    }
    fileStream.close();
    return true;
 }

 bool CondMaxSearch(vector<int> &x, int &maxi, int &ind){

    bool l = false;

    for(int i =1; i< (x.size()-1); i++){

        if(!(x[i-1]>= x[i] && x[i]<= x[i+1])){}

        if(l && (x[i-1]>= x[i] && x[i]<= x[i+1])){
            if(maxi < x[i]){
               maxi = x[i];
               ind = i;

            }


        }
        if((!l) && (x[i-1]>= x[i] && x[i]<= x[i+1])){

            l = true;
            maxi = x[i];
            ind = i;
        }
    }

 return l;
 }


 bool MaxSearchFile(const string filename , int &maxi){
    fstream fileStream(filename);
    int before,current,after;

    fileStream >> before;
    fileStream >> current;
    fileStream >> after;

    bool l = false;

    while(! fileStream.fail()){

        if (l && (before >= current && after >= current) ){

            if (maxi < current){

                maxi = current;
            }

        }
        if (!l && (before >= current && after >= current))
        {

            l = true;
            maxi = current;
        }

        before = current;
        current = after;
        fileStream >> after;
    }


    return l;


 }

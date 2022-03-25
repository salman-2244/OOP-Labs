#include <iostream>
#include "inFile.h"
using namespace std;

int main()
{

    bool fileerror = true;

    do
    {
        try {

            string filename;
            cout<<"File's name :";
            cin>>filename;

            inFile t(filename);

            for(t.first(); !t.end(); t.next())
            {
                cout<<t.current()<<endl;
            }
            fileerror = false;


        } catch (inFile:: Errors err)
        {

            cerr<< "File Opening Unsucessful"<<endl;
        }


    } while (fileerror);

    return 0;
}

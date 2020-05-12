
//File IO

#include "helloworld.hpp"

int main() {
    string line;
    //create an output stream to write to the file
    //append new lines to the end of the file
    fstream myfileI ("input.txt",ios::app);
    if (myfileI.is_open())
    {
        myfileI<<"\n I am adding a new line. \n";
        myfileI<<"\n I am adding another new line \n";
        myfileI.close();
    }
    else
    {
        cout<<"Unable to open the file for writing";
    }

    //creating an input stream to read file
    fstream myfileO ("input.txt");
    if(myfileO.is_open())
    {
        while(getline(myfileO, line))
        {
            cout<<line<<"\n";
        }
        myfileO.close();
        system("pause");
    }
      else
    {
        cout<<"Unable to open the file for writing";
    }
    return 0;
}
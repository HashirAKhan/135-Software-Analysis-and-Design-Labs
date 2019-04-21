//Hashir Khan
//CSCI 135
//04-11-19
//Lab 9D

#include <iostream>
using namespace std;

//creates peoem
string * createAPoemDynamically() {
    string *p = new string;
    *p = "Roses are red, violets are blue";
    return p;
}


int main() {
    while(true) {
        string *p;
        p = createAPoemDynamically();
        delete p;   //deletes P
        // assume that the poem p is not needed at this point
        //will run infinitly
    }
}

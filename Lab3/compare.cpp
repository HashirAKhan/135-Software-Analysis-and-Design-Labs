//Hashir Khan
//2-11-19
//CSCI 133
//Project 3C

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;

int main() {
	ifstream fin("Current_Reservoir_Levels.tsv");
	if (fin.fail()) {
   	cerr << "File cannot be opened for reading." << endl;
   	exit(1); // exit if failed to open the file
	}
	string junk;        // new string variable
	getline(fin, junk); // read one line from the file 
	string date;
	double eastSt, eastEl, westSt, westEl;
	string start, end;
	bool run = false;
	cout<<"Enter starting date: ";
	cin>>start;
	cout<<endl<<"Enter ending date: ";
	cin>>end;
	cout<<endl;
	while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) { 
   	// this loop reads the file line-by-line
   	// extracting 5 values on each iteration 
    
   	fin.ignore(INT_MAX, '\n'); //skips to the end of line, 
                          //ignorring the remaining columns 
		
		if(start == date){
			run = true;		
		}
	
		if (run){
			if(eastEl>westEl){
				cout<<date<< " East"<<endl;
			}
			else if(westEl>eastEl){
				cout<<date<< " West"<<endl;		
			}
			else if(eastEl==westEl){
				cout<<date<< " Equal"<<endl;
			}
		}
	
		if(end == date){
			run = false;
		}	
	}
	fin.close();
	

}

//Hashir Khan
//2-11-19
//CSCI 133
//Project 3D

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
	string dates[366];
	double num[366];
	int index = 0;
	while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) { 
   	// this loop reads the file line-by-line
   	// extracting 5 values on each iteration 
    
   	fin.ignore(INT_MAX, '\n'); //skips to the end of line, 
                          //ignorring the remaining columns 
		
		if(start == date){
			run = true;		
		}
	
		if (run){
			dates[index]=date;
			num[index]=westEl;
			index++;
		}
	
		if(end == date){
			run = false;
		}	
	}
	
	for (int i = index -1;i >= 0; i--){
		cout<<dates[i]<<" "<<num[i]<<" ft"<<endl;	
	}
	fin.close();
	

}

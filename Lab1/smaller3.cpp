//Hashir Khan
//CSCI 136
//Project 1B
// 1-28-19

#include <iostream>
using namespace std;

int main() {
	cout<<"Enter first integer :"<< endl;
	int x; //Stores the first integer
	cin>>x;
	cout<<"Enter second integer :"<< endl;
	int y; //Stores the second integer
	cin>>y;
	cout<<"Enter thrid integer :"<< endl;
	int z; //Stores the third integer
	cin>>z;
	if(x>y){  //compares the first inteer to the second
		if(y<z){   //if the second is smaller then the second is compared to the frist
			cout<<"The smaller of the three numbers is "<<y;
		}
		if(z<y){  //If the third is smaller
			cout<<"The smaller of the three numbers is "<<z;
		}
	}
	else{  // else it checks to see if the frist integer is the smaller one when compared to te second
		if(x<z){  //If first is smaller than the third
			cout<<"The smaller of the three numbers is "<<x;
		}
		if(z<x){  // If the third is the smaller one when compared to the first
			cout<<"The smaller of the three numbers is "<<z;
		}
	}
}

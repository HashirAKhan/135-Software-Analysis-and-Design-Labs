//Hashir Kha
//CSCI 136
//Project 1A
// 1-28-19

#include <iostream>
using namespace std;

int main() {
	cout<<"Enter first integer :"<< endl;
	int x; //Holds the first integer
	cin>>x;
	cout<<"Enter second integer :"<< endl;
	int y; //Holds the second integer
	cin>>y;
	if(x>y){  //checks to see if the first integer is larger than the second
		cout<<"The smaller of the two numbers is "<<y;
	}
	else{  //If not than the first integer is the smaller one
		cout<<"The smaller of the two numbers is "<<x;
	}
}

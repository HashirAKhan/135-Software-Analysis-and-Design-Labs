//Hashir Khan
//2-4-19
//CSCI 136
//Project 2A

//This program takes a number as an input from the user
//and checks to see if that number is with in range of 
//0 through 100 exclusive and then prints out the number
//squared
#include <iostream>
using namespace std;

int main(){
	int input;
	cout<<"Enter an integer from 0 to 100 :";
	cin>>input;
	while(input < 1 || input > 99){
		cout<<endl<<"Please enter a valid number :";
		cin>>input;
	}
	cout<<endl<<"Number squared is "<<input*input;
	return 0;
}

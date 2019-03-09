//Hashir Khan
//2-4-19
//CSCI 136
//Project 2C

//This program creates an int array with
//length 10 filled with 1s and allows the 
//user to change any of its content to a
//desired value.

#include <iostream>
using namespace std;

int main(){
	int x[10];
	for (int i = 0; i < 10; i++){
		x[i] = 1;	
	}
	int index= 0;
	int value= 1;
	do {
		x[index]=value;
		for (int i =0; i < 10; i++){
			cout<<x[i]<<" ";		
		}
		cout<<endl<<"input index: ";
		cin>>index;
		cout<<endl<<"input value: ";
		cin>>value;
	}while ( index >-1 && index < 10);
	cout<<endl<<"Index out of range. Exit.";
	return 0;
}

//Hashir Khan
//2-4-19
//CSCI 136
//Project 2D

//This program prints out the first 60 numbers in the
//fibonacci sequence using for loops to create an array
//with all of the number in it.
#include <iostream>
using namespace std;

int main(){
	int fib[60];
	fib [0] = 0;
	fib [1] = 1;
	for (int i = 2; i < 60; i++){
		fib[i]=fib[i-1]+fib[i-2];	
	}
	for (int i = 0; i < 60; i++){
		cout<<fib[i]<<endl;
	}
}

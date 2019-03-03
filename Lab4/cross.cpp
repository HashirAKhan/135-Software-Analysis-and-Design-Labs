//Hashir Khan
//135
//Project 4c
//2-20-2019

#include <iostream>
using namespace std;

int main(){
  int x,y;
  cout<<"Enter size: ";
  cin>>x;  //takes size from user
  cout<<endl;
  for (int i = 0; i < x; i++){    //keeps track of what line we are on
    for (int j = 0; j < x; j++){  //keeps track of what part of the line we are on
      if(j==i||j==(x-1)-i){
        cout<<"*";  //outputs *
      }
      else {
        cout<<" ";  //outputs space
      }
    }
    cout<<endl;   //goes to next line
  }
  return 0;
}

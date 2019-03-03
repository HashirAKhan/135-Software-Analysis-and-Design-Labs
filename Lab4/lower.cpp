//Hashir Khan
//135
//Project 4d
//2-20-2019

#include <iostream>
using namespace std;

int main(){
  int x,y;
  cout<<"Enter side lenght: ";
  cin>>x;  //takes size from user
  cout<<endl;
  for (int i = 0; i < x; i++){    //keeps track of what line we are on
    for (int j = 0; j <= i; j++){  //keeps track of how many starts per line
      cout<<"*";
    }
    cout<<endl;   //goes to next line
  }
  return 0;
}

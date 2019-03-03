//Hashir Khan
//135
//Project 4A
//2-20-2019

#include <iostream>
using namespace std;

int main(){
  int x,y;
  cout<<"Enter width: ";
  cin>>x;  //takes width from user
  cout<<endl<<"Enter height: ";
  cin>>y;  //takes hight from user
  cout<<endl;
  for (int i = 0; i < y; i++){
    for (int j = 0; j < x; j++){
      cout<<"*";  //adds x amount of *s
    }
    cout<<endl; //goes to next line
  }
  return 0;
}

//Hashir Khan
//135
//Project 4B
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
      if ((i+j)%2==0){  //alternates the stars
        cout<<"*";
      }
      else{  //alternates the spaces
        cout<<" ";
      }
    }
    cout<<endl;
  }
  return 0;
}

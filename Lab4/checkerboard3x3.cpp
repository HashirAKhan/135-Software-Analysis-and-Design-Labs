//Hashir Khan
//135
//Project 4g
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
  int space = 0; // keeps track of row spaces
  int star = 0; //keeps track of row stars
  bool z = true; //makes sure the columbs alternate
  int count = 0;  //keeps track of when to make the columbs alternate
  for (int i = 0; i< y; i++){
    for (int j = 0; j < x; j++){
      if (z){
        if(star<3){
          cout<<"*";
          star++;
        }
        else{
          cout<<" ";
          space++;
          if(space==3){
            star = 0;
            space = 0;
          }
        }
      }
      else{
        if(space<3){
          cout<<" ";
          space++;
        }
        else{
          cout<<"*";
          star++;
          if(star==3){
            star=0;
            space=0;
          }
        }
      }
    }
    star=0;//resets everything
    space=0;
    cout<<endl;
    count++;  //adds vertical count
    if (count==3){
      if(z){
        z = false;
      }
      else{
        z = true;
      }
      count = 0;
    }
  }
  return 0;
}

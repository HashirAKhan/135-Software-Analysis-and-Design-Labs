//Hashir Khan
//135
//Project 4f
//2-21-2019

#include <iostream>
using namespace std;

int main(){
  int x,y;
  cout<<"Enter width: ";
  cin>>x;  //takes size from user
  cout<<endl<<"Enter length: ";
  cin>>y;
  cout<<endl;
  int stars = x;
  int space = 0;
  if((x+1)/2>=y){  //checks to see if the size works
  for (int i = 0; i < y; i++){    //keeps track of what line we are on
        for (int k = 0; k < space; k++){
          cout<<" ";
         }
         for (int k = 0; k < stars; k++){
           cout<<"*";
          }
          for (int k = 0; k < space; k++){
            cout<<" ";
           }
    stars-=2; //changes the amount of stars and spaces needed
    space+=1;
    cout<<endl;   //goes to next line
  }
}
else{
   cout<<"Impossible shape!";
}
  return 0;
}

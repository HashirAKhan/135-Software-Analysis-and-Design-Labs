//Hashir Khan
//CSCI 136
//LAB 12
//05-08-2019

#include <iostream>
#include <vector>


//Creates a vector of size n and counts from 0 to n-1
std::vector<int> makeVector(int n){
  std::vector<int> result;
  for(int i = 0; i < n; i++){
    //adds element i to the end of the vector
    result.push_back(i);
  }

  //returns the vector
  return result;
}

int main(){
  return 0;
}

//Hashir Khan
//CSCI 136
//LAB 12
//05-08-2019

#include <iostream>
#include <vector>


//This function takes in a vector and returns a vector with only positive values
std::vector<int> goodVibes(std::vector<int> v){
  std::vector<int> result;

  //loop through the original vector
  for(int i = 0; i < v.size(); i++){

    //checks to see if the value is positive
    if(v[i]>0){

      //adds the positive value to the return vector
      result.push_back(v[i]);
    }
  }
  return result;
}

int main(){
  return 0;
}

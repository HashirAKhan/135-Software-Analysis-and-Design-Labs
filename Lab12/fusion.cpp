//Hashir Khan
//CSCI 136
//LAB 12
//05-08-2019

#include <iostream>
#include <vector>

//This function takes in 2 vectors
//puts all elements from vector 2 into vector 1
//and then clears vector 2
void gogeta(std::vector<int> &goku, std::vector<int> &vegeta){

  //loops through all elements of vegeta
  for (int i = 0; i < vegeta.size(); i++){

    //adds every element into goku
    goku.push_back(vegeta[i]);
  }

  //clears veteta
  vegeta.clear();

}

int main(){
  return 0;
}

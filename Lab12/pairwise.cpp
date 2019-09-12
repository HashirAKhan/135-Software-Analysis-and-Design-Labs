//Hashir Khan
//CSCI 136
//LAB 12
//05-08-2019

#include <iostream>
#include <vector>

//returns an array with all added elements from v1 and v2
std::vector<int> sumPairWise(std::vector<int> &v1, std::vector<int> &v2){
  std::vector<int> result;
//checks to see which array is bigger
  if (v1.size()>v2.size()){
    //adds sum of all the elements from both arrays
    for(int i = 0; i < v2.size(); i++){
      result.push_back(v1[i]+v2[i]);
    }
    //adds the remaining elements from the larger array
    for (int i = v2.size(); i < v1.size(); i++){
      result.push_back(v1[i]);
    }
  }
  //repeated from the if statement but in reverse
  else{
    for(int i = 0; i < v1.size(); i++){
      result.push_back(v1[i]+v2[i]);
    }
    for (int i = v1.size(); i < v2.size(); i++){
      result.push_back(v2[i]);
    }
  }
  return result;
}
int main(){
  return 0;
}

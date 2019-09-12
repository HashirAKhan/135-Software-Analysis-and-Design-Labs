//Hashir Khan
//CSCI 136
//Lab 13
//5-13-2019

#include<iostream>


//prints out a range of numbers
void printRange(int left, int right){
  if(left<=right){
    std::cout<<std::to_string(left)<<" ";
    printRange(left+1, right);
  }
  else{
    std::cout<<std::endl;
  }
}


//returns the sum at a range of numbers
int sumRange(int left, int right){
  if(left<=right){
    return sumRange(left+1, right) + left;
  }
  return 0;
}

//helper function
//sum in an array range
int sumArrayInRange(int *arr, int left, int right){
  if(left<right){
    return sumArrayInRange(arr, left+1, right) + arr[left];
  }
  return 0;
}


//returns the sum of an array
int sumArray(int *arr, int size){
  return sumArrayInRange(arr, 0, size);
}


// sees if a string is alpha numeric
bool isAlphanumeric(std::string s){
  if(s.length()==0){
    return true;
  }
  if(s.length()==1){
    return isalnum(s[0]);
  }
  if(!isalnum(s[0])){
    return false;
  }
  return isAlphanumeric(s.substr(1));
}


//this function checks to see if the parenthesis are correct
bool nestedParens(std::string s){
  if(s.length()==0){
    return true;
  }

  if(s[0]!='('||s[s.length()-1]!=')'){
    return false;
  }

  return nestedParens(s.substr(1,s.length()-2));
}


int main(){

  std::cout<<nestedParens("(())");
  return 0;
}

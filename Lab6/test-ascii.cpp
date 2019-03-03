//Hashir Khan
//135
//Project 6A
//2-28-2019

#include <iostream>

//Function takes input from the user and returns the ASCII code of each
//character
int main(){
  std::string input;
  std::cout<<"Input: ";
  getline(std::cin, input);  //Gets user input
  for(int i = 0; i < input.length(); i++){
    std::cout<<std::endl<<input[i]<<" "<<(int)input[i];  //prints out the character
  }                                                      //as well as the ASCII code
}

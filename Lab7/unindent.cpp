//Hashir Khan
//135
//Project 7A
//3-22-2019
#include<iostream>
#include<cctype>

std::string removeLeadingSpace(std::string line){
  std::string result;
  bool start = false;
  for(int i = 0; i < line.length(); i++){
    if (!isspace(line[i])){
      start = true;
    }
    if (start){
      result += line[i];
    }
  }
  return result;
}

int main(){
  std::string line;
  while(getline(std::cin, line)){
    std::cout<<removeLeadingSpace(line)<<std::endl;
  }
}

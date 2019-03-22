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

int countChar(std::string line, char c){
  int count = 0;
  for(int i = 0; i < line.length(); i++){
    if (line[i]==c){
      count++;
    }
  }
  return count;
}



int main(){
  std::string line;
  int tab = 0;
  while(getline(std::cin, line)){
    for (int i = 0; i < tab; i++){
      std::cout<<"\t";
    }
    std::cout<<removeLeadingSpace(line)<<std::endl;
    tab+=countChar(line, '{');
    tab-=countChar(line, '}');
  }
  return 0;
}

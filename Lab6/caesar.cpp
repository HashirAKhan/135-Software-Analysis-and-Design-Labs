//Hashir Khan
//135
//Project 6B
//2-28-2019

#include <iostream>


char shiftRight(char c, int rightShift){
  if(!isalpha(c)){
    return c;
  }
  char result = c + rightShift;
  if(!isalpha(result)){
    result-=26;
  }
  if(c<91&&result>90){
    result-=26;
  }
  return result;
}


std::string encryptCaesar(std::string text, int rightShift){
  std::string result = "";
  for (int i = 0; i < text.length(); i++){
    result += shiftRight(text[i], rightShift);
  }
  return result;
}



int main(){
  std::cout<<encryptCaesar("Very Hot", 5)<<std::endl;
//  std::cout<<shiftRight('W',12);
}

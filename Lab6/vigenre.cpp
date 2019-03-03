//Hashir Khan
//135
//Project 6C
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

std::string encryptVigenre(std::string text, std::string key_word){
  int index = 0;
  std::string result = "";
  for (int i = 0; i < text.length(); i++){
      result+=shiftRight(text[i],((int)key_word[index])-97);
      index++;
      if(index == key_word.length()){
        index = 0;
      }
  }
  return result;
}

int main(){
  std::cout<<encryptVigenre("Hello my name is","food");
  return 0;
}

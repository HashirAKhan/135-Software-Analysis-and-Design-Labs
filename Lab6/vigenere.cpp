//Hashir Khan
//135
//Project 6C
//2-28-2019

#include <iostream>

//shifts the character
char shiftChar(char c, int rightShift){
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

//runs the encryption function
std::string encryptVigenere(std::string text, std::string key_word){
  int index = 0;
  std::string result = "";
  for (int i = 0; i < text.length(); i++){
      while (!isalpha(text[i])&& i<text.length()){   //just adds the non alphabet and moves to next char
        result += text[i];
        i++;
      }
      if(i<text.length()){
        result+=shiftChar(text[i],((int)key_word[index])-97);
        index++;
        if(index == key_word.length()){
          index = 0;
        }
      }
  }
  return result;
}

//runs main method
int main(){
  std::string input, key;  //stores users message
  std::cout<<"Enter a message: ";
  getline(std::cin, input);
  std::cout<<std::endl<<"Enter the key  : ";
  std::cin>>key; //stores the key
  std::cout<<std::endl<<"Ciphertext     : "<<encryptVigenere(input, key);
}

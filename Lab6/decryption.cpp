//Hashir Khan
//135
//Project 6D
//2-28-2019

#include <iostream>

char shiftLeft(char c, int lshift){
  if (!isalpha(c)){
    return c;
  }
  char result = c - lshift;
  if(!isalpha(result)){
    result += 26;
  }
  if(c>96&&result<97){
    result += 26;
  }
  return result;
}

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

std::string decryptCaesar(std::string text, int rshift){
  std::string result = "";
  for (int i = 0; i < text.length(); i++){
    result += shiftLeft(text[i], rshift);
  }
  return result;
}

std::string decryptVigenre(std::string text, std::string key){
  int index = 0;
  std::string result = "";
  for (int i = 0; i < text.length(); i++){
    result+=shiftLeft(text[i],((int)key[index])-97);
    index++;
    if(index == key.length()){
      index = 0;
    }
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
  std::cout<<"Enter Plaintext: ";
  std::string text, keyWord;
  int rshift;
  std::getline(std::cin,text);
  std::cout<<std::endl<<std::endl<<"= Caesar ="<<std::endl<<"Enter shift     : ";
  std::cin>>rshift;
  std::cout<<std::endl<<"Ciphertext      : "<<encryptCaesar(text,rshift)<<std::endl;
  std::cout<<"Decrypted       : "<<decryptCaesar(encryptCaesar(text,rshift), rshift)<<std::endl;
  std::cout<<std::endl<<"=  Vigenre  ="<<std::endl<<"Enter keyword   : ";
  std::cin>>keyWord;
  std::cout<<std::endl<<"Ciphertext      : "<<encryptVigenre(text,keyWord)<<std::endl;
  std::cout<<"Decrypted       : "<<decryptVigenre(encryptVigenre(text,keyWord),keyWord);
  std::cout<<std::endl;
  return 0;
}

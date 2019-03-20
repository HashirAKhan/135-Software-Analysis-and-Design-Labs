//Hashir Khan
//135
//Project 6B
//2-28-2019

#include <iostream>

//helper function for encryptCaesar
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

//This method encrypts the function
std::string encryptCaesar(std::string text, int rightShift){
  std::string result = "";
  for (int i = 0; i < text.length(); i++){
    result += shiftChar(text[i], rightShift);
  }
  return result;
}


//main function
int main(){
  std::string input;  //stores users message
  int shift;          // stores the amount of shift needed
  std::cout<<"Enter a message: ";
  getline(std::cin, input);
  std::cout<<std::endl<<"Enter the shift: ";
  std::cin>>shift;
  std::cout<<std::endl<<"Ciphertext     : "<<encryptCaesar(input, shift);

}

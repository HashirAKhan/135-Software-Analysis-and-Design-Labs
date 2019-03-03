//Hashir Khan
//135
//Lab 5A
//2-27-2019

#include <iostream>

//This function checks to see if x is divisible by y
bool isDivisibleBy(int x, int y){
  if(y==0){
    return false;
  }
  if(x%y==0){
    return true;
  }
  return false;
}

//This function checks to see if x is prime
bool isPrime(int x){
  if(x==1){
    return false;
  }
  for (int i = 0; i < x; i++){
    if(i != 1 && isDivisibleBy(x, i)){
      return false;
    }
  }
  return true;
}

//This function finds the next primne number greater than x
int nextPrime(int x){
  for (int i = x+1; i > x; i++){
    if(isPrime(i)){
      return i;
    }
  }
  return -1;
}

//This function counts the amount of prime numbers between x and y;
int countPrime(int x, int y){
  int count = 0;
  for (int i = x; i <= y; i++){
    if (isPrime(i))
    count++;
  }
  return count;
}

//This function checks to see if a is a twin prime
//A twin prime is a prime number 'a' where a+2 or a-2
//are also prime numbers.
bool isTwinPrime(int a){
  if(isPrime(a)){
    if (isPrime(a-2)||isPrime(a+2)){
      return true;
    }
  }
  return false;
}

//This function finds the next twin prime number greater than a
int nextTwinPrime(int a){
  bool loop = true;
  int index = a+1;
  while(loop){
    if(isTwinPrime(index)){
      loop=false;
      return index;
    }
    index++;
  }
  return -1;
}

//This function finds the largest twin prime number between x and y
int largestTwinPrime(int x, int y){
  for (int i = y; i >= x; i--){
    if (isTwinPrime(i)){
      return i;
    }
  }
  return -1;
}

/* Lab 5A
int main(){
  int a,b;
  std::cout<<"Enter Divident: ";
  std::cin>>a;
  std::cout<<std::endl<<"Enter Divisor: ";
  std::cin>>b;
  if(isDivisibleBy(a,b)){    //checks to see if isDivisibleby(a,b) is true which
    std::cout<<std::endl<<"Yes"; //would mean a is divisible by b
  }
  else{                     //else they or not divisible
    std::cout<<std::endl<<"No";
  }
  return 0;
}
*/

/* Lab 5B
int main(){
  int a;
  std::cout<<"Enter a number: ";
  std::cin>>a;
  std::cout<<std::endl;
  if(isPrime(a)){
    std::cout<<"Yes";
  }
  else{
    std::cout<<"No";
  }
  return 0;
}
*/


/*  Lab 5C
int main(){
  int a;
  std::cout<<"Enter a number: ";
  std::cin>>a;

  std::cout<<std::endl<<"The next prime number is: "<<nextPrime(a);
  return 0;
}
*/

/*  Lab 5D
int main(){
  int a,b;
  std::cout<<"Enter the lower limit :";
  std::cin>>a;
  std::cout<<std::endl<<"Enter the upper limit :";
  std::cin>>b;
  std::cout<<std::endl<<"There are "<<countPrime(a, b)<<" prime numbers in that range.";
}
*/

/* Lab 5E
int main(){
  int a;
  std::cout<<"Enter a number: ";
  std::cin>>a;
  std::cout<<std::endl;
  if(isTwinPrime(a)){
    std::cout<<a<<" is a twin prime";
  }
  else{
    std::cout<<a<<" is not twin prime";
  }
  return 0;
}
*/

/* Lab 5F
int main(){
  int a;
  std::cout<<"Enter a number: ";
  std::cin>>a;
  std::cout<<std::endl<<"The next twin prime number is : "<<nextTwinPrime(a);
  return 0;
}
*/

/* Lab 5G
int main(){
  int a,b;
  std::cout<<"Enter the lower limit :";
  std::cin>>a;
  std::cout<<std::endl<<"Enter the upper limit :";
  std::cin>>b;
  std::cout<<std::endl<<"The largest twin prime number is : "<<largestTwinPrime(a, b);
}
*/

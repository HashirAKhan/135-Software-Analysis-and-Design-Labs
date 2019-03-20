//Hashir Khan
//03-12-19
//CSCI 135
//Project 2A

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>

//Function return the correspond mRNA base of a DNA base
char DNAbase_to_mRNAbase(char dna_base){
  dna_base = toupper(dna_base);
  char rna_base = ' ';         //store mRNA base
  switch (dna_base){            //Basically like a bunch of
    case 'A': rna_base = 'U';   //if statements going through
      break;                    //the possible values of the
    case 'T': rna_base = 'A';   //DNA base
      break;
    case 'C': rna_base = 'G';
      break;
    case 'G': rna_base = 'C';
      break;
  }
  return rna_base;             //returns the mRNA base
}

//Function that loops through entire DNA strand to get the mRNA strand
std::string DNA_to_mRNA(std::string dna_strand){
  std::string rna_strand = "";                       //stores the mRNA strand
  for (int i = 0; i < dna_strand.length(); i++ ){    //loops through the DNA strand
    rna_strand += DNAbase_to_mRNAbase(dna_strand[i]);//adds each mRNA base to the strand
  }
  return rna_strand;  //return the mRNA strand
}

int main(){
  std::ifstream fin("dna.txt");  //Opens File
    if (fin.fail()) { //if it failes to open up
        std::cerr << "File cannot be read, opened, or does not exist.\n";
        exit(1);
    }
    std::string strand;  //will hold the DNA sequence

    //Gets input from txt file
    while(fin >> strand) {
        std::cout<<DNA_to_mRNA(strand)<<std::endl;  //prints out mRNA strand
    }
    fin.close(); //close the program
}

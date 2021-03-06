//Hashir Khan
//03-13-19
//CSCI 135
//Project 2B

#include <iostream>
#include <fstream>

//Function return the correspond mRNA base of a DNA base
char DNAbase_to_mRNAbase(char dna_base){
  dna_base = toupper(dna_base);
  char rna_base;                //store mRNA base
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

//This function will take a DNA strand, Convert it to mRNA using the functions
//above. Then it will take every three characters from the mRNA strands which
//will be out codons. It then uses the codons with codons.tsv to fine what amino_acid
//it will translate too and adds that to the Polypeptid chain
std::string DNA_strand_to_Polypetide_chain(std::string DNA_strand){
  std::string Polypetide_chain, mRNA_strand, currentcodon, codon, amino_acid;
  bool run = false;                              //The booleon is important because
  std::fstream dict ("codons.tsv");              //We need to find the starting amino acid
                                                 //which is "Met" before we start recording all
  mRNA_strand = DNA_to_mRNA(DNA_strand);         //The amino acids.
  //Converted DNA to mRNA

  //This for loop will go through every 3 characters in the mRNA_strand
  //In other words the codons in the mRNA_strand
  for(int i = 0; i<mRNA_strand.length(); i+=3){
    dict.seekg(0);                              //The seekg(0) functions makes the
    currentcodon = mRNA_strand.substr(i,3);     //computer read the file back from the
                                                //start again. We need this so we can look
    do{                                         //through all the amino acids when we look for
      dict>>codon>>amino_acid;                  //out next codon
    }while(codon!=currentcodon);

    if(amino_acid == "Stop"){   //If we run into a stop codon, break out of the for loop
      break;                    //and end the function after returning what we have in our
    }                           //Polypetide chain

    else if (amino_acid == "Met"){ //Else if we have our starting codon, add it in without
      Polypetide_chain += "Met";   //a "-" before it since its out first amino acid
      run = true;                  //and set run to true because we can start adding in other
    }                              //amino acids

    else if (run){                          //Else if we have already seen out starting codon,
      Polypetide_chain += "-" + amino_acid; //we can add in other amino acids
    }
  }
  return Polypetide_chain;  //returning our final amino acid chain.
}


int main(){
  std::fstream file ("dna2b.txt");//First file used to read the DNA strands
  std::string DNA_strand;         //Variable to store the DNA strands from file

  while(getline(file,  DNA_strand)){ //Will run until all DNA strands are read
    std::cout<<DNA_strand_to_Polypetide_chain(DNA_strand)<<std::endl;  //printing out the amino acids
  }
  return 0;
}

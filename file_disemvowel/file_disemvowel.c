#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define BUF_SIZE 1024

bool is_vowel(char c) {
  bool isCharVowel;
  switch(c) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':

        isCharVowel = true;

    default:
        isCharVowel = false;
  }
  return isCharVowel;
}

int main(int argc, char *argv[]) {
  FILE *inputFile;
  FILE *outputFile;
  
  if(argc == 1){
    inputFile = stdin;
    outputFile = stdout; 
  }
  else if( argc == 2 ){
    inputFile = fopen(argv[1], "r");
    outputFile = stdout;
  }
  else if(argc == 3){
    inputFile = fopen(argv[1], "r"); 	
    outputFile = fopen(argv[2], "w");
  }
  // exit if too many command line arguments are given
  else{
    printf("too many arguements give given.");
    exit(0);
  }

disemvowel(inputFile, outputFile);
return 0;
}   


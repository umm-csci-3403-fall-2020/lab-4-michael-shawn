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
        return isCharVowel;
    default:
        isCharVowel = false;
	return isCharVowel;
  }
  return isCharVowel;
}

int copy_non_vowels(int num_chars, char* in_buffer, char* out_buffer) {
  int i;
  int num_vowels = 0;
  for (i=0; i < num_chars-2; i++) {
    if (is_vowel(in_buffer[i]) == false) {
      out_buffer[num_vowels] = in_buffer[i];
      num_vowels++;
    }
  }
  return num_vowels;
}

void disemvowel(FILE* inputFile, FILE* outputFile) {
  char* in_buffer = (char*)calloc(BUF_SIZE, sizeof(char));
  char* out_buffer = (char*)calloc(BUF_SIZE, sizeof(char));
    
    int num_chars = 1;
    int non_vowels;
    while(num_chars != 0) {
      num_chars = fread(in_buffer, sizeof(char), BUF_SIZE, inputFile);
      non_vowels = copy_non_vowels(num_chars, in_buffer, out_buffer);
      fwrite(out_buffer, sizeof(char), non_vowels, outputFile);
    }
    free(in_buffer);
    free(out_buffer);
}

int main(int argc, char *argv[]) {
  FILE *inputFile = stdin;
  FILE *outputFile = stdout;
   
  if( argc >= 2 ){
    inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
      perror("fopen()");
      exit(1);
    }
  }

  if(argc == 3){ 	
    outputFile = fopen(argv[2], "w");
    if (outputFile == NULL) {
      perror("fopen()");
      exit(1);
    }
  }

disemvowel(inputFile, outputFile);

fclose(inputFile);
fclose(outputFile);
return 0;
}   


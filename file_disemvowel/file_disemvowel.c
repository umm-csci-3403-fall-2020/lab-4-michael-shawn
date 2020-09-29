#include <stdio.h>
#include <stbool.h>

#define BUF_SIZE 1024

bool is_vowel(char c) {
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

        bool isVowel = true;

    default:
	bool isVowel = false;
  }
  return isVowel;
}

#include <ctype.h>
#include <stdio.h>

int main(int argc, char **argv) {
  /*
  Create a program which opens a file specified on the command line and counts:
  - number of lines
  - number of characters
  - number of words
  Before printing them to the user.

  You can do this without storing the file contents in your program.
  You may want to use the isspace() function from the ctype library.

  Ensure that you have appropriate validation.
  */

  FILE *fp = fopen(argv[1],"r");
  
  if(fp == NULL){
    printf("Error file not found");
    return 1;
  }

  int number_lines;
  int number_characters;
  int number_words;
  char buffer[100];




}
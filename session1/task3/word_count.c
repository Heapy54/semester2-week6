#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>

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

  int number_lines = 0;
  int number_characters = 0;
  int number_words = 0;
  char buffer[100];
  char ch;
  bool is_word = false;

  //read the file character by character
  while((ch = fgetc(fp)) != EOF){
    number_characters +=1;
    if(ch == '\n'){
      number_lines +=1;
    }
    if(isspace(ch)){
      is_word = false;
    }
    else{
      number_words +=1;
      is_word = true;
    }
  }

  //print the results
  printf("Results: \n");
  printf("Number of lines: %d\n",number_lines);
  printf("Number of characters: %d\n",number_characters);
  printf("Number of words: %d\n",number_words);

}
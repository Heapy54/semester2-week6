#include <ctype.h>
#include <stdio.h>

int main(int argc, char **argv) {
  /*

  Create a program which opens a file specified on the command line and performs
  a frequency analysis on the letters in the file - i.e. counts how many times
  each letter is used. Then print this out to the user.

  ADVANCED: create a new file which holds the frequency analysis data.

  You should consider A and a to be the same letter - you can use toupper() from
  ctype to help.

  You can do this without storing the file contents in your program.

  Ensure that you have appropriate validation.

  */

  //validate the command line
  if(argc < 2){
    printf("Usage: %s <input_file> [output_file]\n", argv[0]);
    return 1;
  }

  //open the input file
  FILE *input = fopen(argv[1], "r");
  if(input == NULL){
    printf("Error: Could not open the input file\n");
    return 1;
  }

  int frequency[26] = {0}; //initilises all the values to 0
  int ch;

  //read the file character by character
  while((ch = fgetc(input)) != EOF){
    if(isalpha(ch)){
      ch = toupper(ch);
      frequency[ch - 'A']++;
    }
  }

  //print the results to console
  printf("Letter Frequency Analysis: \n");
  for(int i = 0 ; i< 26; i++){
    printf("%c: %d\n", 'A'+i, frequency[i]);
  }

  //advanced : write to an output file if provided
  if (argc >= 3) {
        FILE *output = fopen(argv[2], "w");
        if (output == NULL) {
            printf("Error: Could not create output file.\n");
            return 1;
        }

        fprintf(output, "Letter Frequency Analysis:\n");
        for (int i = 0; i < 26; i++) {
            fprintf(output, "%c: %d\n", 'A' + i, frequency[i]);
        }

        fclose(output);
    }

    return 0;
}
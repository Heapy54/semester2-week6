#include <stdio.h>

int main(int argc, char **argv) {
  /*

  Write a program which accepts 2 file names on the command line, and copies the
  contents of the first into the second.

  e.g.

  ./copy example.txt copyOfExample.txt

  Would read the contents of example.txt and write them into copyOfExample.txt

  You can assume that no file will exceed 100 characters per line or 100 lines
  long - or you could calculate the number of lines and dynamically allocate an
  array.
  */

  if(argc != 3){
    printf("Usage: %s <source file> <desitnation file>\n",argv[0]);
    return 1;
  }

  FILE *source = fopen(argv[1],"r");

  if(source == NULL){
    printf("Error source file not found\n");
    return 1;
  }

  FILE *destination = fopen(argv[2],"w");

    if(destination == NULL){
    printf("Error destination file not found\n");
    fclose(source);
    return 1;
  }

  char buffer[101];

  while(fgets(buffer, sizeof(buffer), source) != NULL){
    fputs(buffer, destination);

  }

  fclose(source);
  fclose(destination);

  printf("File copied successfully\n");

  return 0;
}


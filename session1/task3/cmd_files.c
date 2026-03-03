#include <ctype.h>
#include <stdio.h>

int main(int argc, char **argv) {
  /*
      Change this code so that it takes a filename given as a command line
     argument and reads it line by line.

      Test it with some of the files in /txt_files.
  */

  FILE *file = fopen("txt_files/poem.txt", "r");
  char buffer[100];

  if (file == NULL) {
    printf("Error: File not found.\n");
    return 1;
  }

  while (fgets(buffer, sizeof(buffer), file) != NULL) {
    printf("%s", buffer);
  }

  fclose(file);
  return 0;
}
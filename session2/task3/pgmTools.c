#include <stdlib.h>
#include <stdio.h>

int getUserInput(char *message);
void menu(void);
unsigned char **allocateArray(int height, int width);
unsigned char **read(char *fn, int *a, int *b);
void printImage(unsigned char **p, int a, int b);
void invert_image(unsigned char **p, int height , int width);
unsigned char **rotate_image(unsigned char **p , int *height , int *width);

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Usage: ./pgmTools image_path\n");
    return 0;
  }

  int height, width;
  unsigned char **image;
  image = read(argv[1], &height, &width);

  int choice = -1;

  do {
    choice = -1;
    menu();
    while (choice < 1)
      choice = getUserInput("Enter choice");

    switch (choice) {
    case 1:
      printImage(image, height, width);
      break;
    case 2:
      invert_image(image, height, width);
      break;
    case 3:
      image = rotate_image(image, &height, &width);
      break;
    case 4:
      break;
    case 5:
      return 0;
    default:
      printf("Bad choice\n");
      break;
    }
  } while (1);
}

int getUserInput(char *message) {
  char buffer[100];
  int choice;
  printf("%s: ", message);
  fgets(buffer, 100, stdin);
  int check = sscanf(buffer, "%d", &choice);
  if (!check) {
    return -1;
  }
  return choice;
}

void menu(void) {
  printf("1 - View PGM Image\n");
  printf("2 - Invert Image\n");
  printf("3 - Rotate Image\n");
  printf("4 - Scale Image\n");
  printf("5 - quit\n");
}

unsigned char **allocateArray(int height, int width) {
  unsigned char **array = calloc(height, sizeof(unsigned char *));
  for (int i = 0; i < height; i++) {
    array[i] = calloc(width, sizeof(unsigned char));
  }

  return array;
}

unsigned char **read(char *fn, int *a, int *b) {
  unsigned char header[10];
  int height, width;
  FILE *file = fopen(fn, "r");
  fscanf(file, "%s ", header);
  fscanf(file, "%d %d", &height, &width);
  fscanf(file, "%s ", header);
  unsigned char **image = allocateArray(height, width);
  for (int row = 0; row < height; row++) {
    for (int col = 0; col < width; col++) {
      fscanf(file, "%hhu", &image[row][col]);
    }
  }
  fclose(file);
  *a = height;
  *b = width;
  return image;
}

void printImage(unsigned char **p, int a, int b) {
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < b; j++) {
      printf("%d%s", p[i][j],
             (p[i][j] < 100) ? (p[i][j] < 10) ? "   " : "  " : " ");
    }
    printf("\n");
  }
}

void invert_image(unsigned char **p, int height, int width){
  /** 
   * @brief takes the values in the array and inverts the based of the number they are
   * 
   * @param p is the pointer to the list 
   * @param height is the height of the file
   * @param width is the width of the image file
   * 
   * to convert each value to its new one subtract from 255
  */
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      p[i][j] = 255 - p[i][j];
    }
  }
}

unsigned char **rotate_image(unsigned char **p, int *height, int *width){
  /**
   * @brief Takes the values from an array and rotates them in the given direction
   * 
   * @param p is the pointer to the array
   * @param height is the height of the array
   * @param width is the width of the image
   * @param direction is the way the image will be rotated
   * 
   * rotates an image in the given way
   */

  int oldheight = *height;
  int oldwidth = *width;

  //creates a new array with the opposite sizes

  unsigned char **rotated = allocateArray(oldwidth, oldheight);

  for (int row = 0; row < oldheight; row++) {
    for (int col = 0; col < oldwidth; col++) {
      rotated[col][oldheight-1-row] = p[row][col];
    }
  }

  *height = oldwidth;
  *width = oldheight;

  return rotated;

}
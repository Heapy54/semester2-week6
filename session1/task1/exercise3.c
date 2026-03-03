#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Prints all values from the numbers array
 *
 * @param count number of values in the array
 * @param numbers the array of values
 */
void print_all(int count, int *numbers) {
  for (int i = 0; i < count; i++) {
    printf("%d%c", numbers[i], (i == count - 1) ? '\n' : ' ');
  }
}

/**
 * @brief calculates and returns the sum of values in an array
 *
 * @param count the number of values in numbers
 * @param numbers the array
 * @return int the sum of values
 */
int sum_all(int count, int *numbers) {
  int total = 0;

  for (int i = 0; i < count; i++) {
    total += numbers[i];
  }

  return total;
}

/**
 * @brief Calculates the mean average of values in an array
 *
 * @param count the number of values in the array
 * @param numbers the array
 * @return float the mean average of the values
 */
float average_all(int count, int *numbers) {
  // re-using sum_all()
  int total = sum_all(count, numbers);

  return (float)total / count;
}

/**
 * @brief Calculates the maximum value
 * 
 * @param count the number of values in the array
 * @param numbers the array of numbers
 * @return integer value of the max value and its index
 */

int find_max(int count, int *numbers){
  int max = numbers[0];
  for(int i = 1;i < count; i++){
    if(max < numbers[i]){
      max = numbers[i];
    }
  }
  return max;
}
/**
 * @brief Calculates the minimum value
 * 
 * @param count the number of values in the array
 * @param numbers the array of numbers
 * @return integer value of the min value and its index
 */

int find_min(int count, int *numbers){
  int min = numbers[0];
  for(int i = 1;i < count; i++){
    if(min > numbers[i]){
      min = numbers[i];
    }
  }
  return min;
}

/**
 * @brief Calculates the range
 * @return integer value of the min value and its index
 */

int find_range(int count, int *numbers){
  int max = find_max(count, numbers);
  int min = find_min(count, numbers);
  int range = max - min;

  return range;
}

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Usage: ./averages num1 ... numx\n");
    return 0;
  }

  int *numbers;
  int count = argc - 1;
  char buffer[50];
  int choice = 0;
  int total = 0;
  float mean;
  int min;
  int max;
  int range;

  numbers = calloc(count, sizeof(int));

  for (int i = 0; i < count; i++) {
    int check = sscanf(argv[i + 1], "%d", &numbers[i]);

    if (check != 1) {
      printf("Error: Non-numerical Argument\n");
      return 1;
    }
  }

  do {
    printf("1 - Show all values\n");
    printf("2 - Calculate sum\n");
    printf("3 - Calculate mean\n");
    printf("4 - Calculate min\n");
    printf("5 - Calculate max\n");
    printf("6 - Calculate range\n");
    printf("7 - exit\n");

    printf("Enter choice: ");
    fgets(buffer, sizeof(buffer), stdin);
    int check = sscanf(buffer, "%d ", &choice);

    if (check != 1) {
      printf("Error: Invalid choice\n");
      continue;
    }

    switch (choice) {
    case 1:
      print_all(count, numbers);
      break;
    case 2:
      total = sum_all(count, numbers);
      printf("Total is: %d\n", total);
      break;
    case 3:
      mean = average_all(count, numbers);
      printf("Average is: %.2f\n", mean);
      break;
    case 4:
      min = find_min(count, numbers);
      printf("Min value is : %d\n", min);
      break;
    case 5:
      max = find_max(count, numbers);
      printf("Max value is : %d\n", max);
      break;
    case 6:
      range = find_range(count, numbers);
      printf("Range value is : %d\n", range);
      break;
    case 7:
      printf("Exiting...\n");
      break;
    default:
      printf("Error: Invalid choice\n");
      break;
    }
  } while (choice != 7);

  return 0;
}
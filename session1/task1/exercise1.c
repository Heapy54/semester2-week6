#include <stdio.h>
#include <stdlib.h>

void fine_calculator(int excess_speed, int *fine){
  // Calculate fine based on how much over the limit
    if (excess_speed <= 10) {
      *fine = 50;
    } else if (excess_speed <= 20) {
      *fine = 100;
    } else {
      *fine = 200;
    }
}

int main() {
  int speed_limit, driver_speed, fine = 0;
  char input[20];

  // Get user input for speed limit
  printf("Enter the speed limit: ");
  if (fgets(input, sizeof(input), stdin)) {
    sscanf(input, "%d", &speed_limit);
  }

  // Get user input for driver's speed
  printf("Enter the driver's speed: ");
  if (fgets(input, sizeof(input), stdin)) {
    sscanf(input, "%d", &driver_speed);
  }

  // Determine if the driver is speeding
  if (driver_speed > speed_limit) {
    int excess_speed = driver_speed - speed_limit;

    fine_calculator(excess_speed, &fine);

    printf("Fine: $%d\n", fine);
  } else {
    printf("No fine needed.\n");
  }

  return 0;
}
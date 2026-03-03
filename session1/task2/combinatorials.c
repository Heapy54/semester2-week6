#include <stdlib.h>
#include <stdio.h>

/**
 * @brief recursively calculates the factorial of an integer n.
 * 
 * @param n number to find factorial of.
 * @return int n factorial.
 */
int factorial(int n) {
  // the base case - this determines when the recursion should stop
  if (n == 0) {
    return 1;
  }

  return n * factorial(n - 1);
}

int nCr (int n, int r){
  int n_facrorial = factorial(n);
  int r_facorial = factorial(r);
  int n_sub_r_facorial = factorial(n-r);

  int result = n_facrorial / (r_facorial*n_sub_r_facorial);
  return result;
}

int nPr (int n, int r){
  int n_facrorial = factorial(n);
  int n_sub_r_facorial = factorial(n-r);

  int result = n_facrorial / n_sub_r_facorial;
  return result;
}

int main(int argc, char **argv) {
  /*
  The program should accept a command line argument as follows:
  ./combinatorials n C r
  ./combinatorials n P r

  where n and r are both positive integers, and r is always less than or equal to n.

  for example:
  ./combinatorials 7 C 2

  Your program should then calculate and print out the correct result

  nCr should return the total combinations of r items out of n.
  This is calculated by: n! / (r! (n - r)!)

  nPr should return the total permutations of r items out of n.
  This is calculated by: n! / (n-r)!

  Add appropriate validation to your program to make your code robust.

  You should try and use functions to write your program.

  */

  if(argc < 4){
    printf("Usage: ./combinatorials n C||P r\n");
    return 1;
  }
  
  char buffer[50];
  int n = atoi(argv[1]);
  int r = atoi(argv[3]);
  char *operation = argv[2];
  int result = 0;
  
  if(r<=n){
    printf("r must not be less than or equal to n\n");
    return 1;
  }

  if(*operation == 'c' || *operation == 'C'){
    result = nCr(n, r);
    printf("nCr = %d\n",result);
  }
  else if (*operation == 'p' || *operation =='P' ){
    result = nPr(n,r);
    printf("nPr = %d\n",result);
  }
  else{
    printf("Enter a valid operation either C or P");
  }

  return 0;
}
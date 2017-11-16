#include <stdio.h>
main() {
  float fahr, celsius;
  float lower, upper, step;
  lower = -17.8;
  upper = 150;
  step = (5.0/9.0);
  printf("\n");
  printf("+----------------+\n");
  printf("| temp conv tab  |\n");
  printf("+----------------+\n");
  printf("| cls --| fhr ---|\n");
  printf("+----------------+\n");
  celsius = lower;
  while (celsius <= upper) {
    fahr = (celsius * (9.0/5.0) + 32.0);
    printf("| %3.1f\t| %6.1f |\n", celsius, fahr);
    celsius = celsius + step;
  }
  printf("+----------------+\n");
  printf("\n");
}

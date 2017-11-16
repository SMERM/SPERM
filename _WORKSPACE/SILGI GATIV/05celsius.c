#include <stdio.h>
main() {
  float fahr, celsius;
  float lower, upper, step;
  lower = 0;
  upper = 300;
  step = 20;
  printf("\n");
  printf("+----------------+\n");
  printf("| temp conv tab  |\n");
  printf("+----------------+\n");
  printf("| fhr --| cls ---|\n");
  printf("+----------------+\n");
  fahr = lower;
  while (fahr <= upper) {
    celsius = (5.0/9.0) * (fahr-32.0);
    printf("| %3.0f\t| %6.1f |\n", fahr, celsius);
    fahr = fahr + step;
  }
  printf("+----------------+\n");
  printf("\n");
}

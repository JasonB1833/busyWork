#include <stdio.h>
#include <stdlib.h>


int main (int argc, char *argv[])
{
  int minutes;
  double minToYr;
  double years;
  double days;

  printf("Please enter an amount of minutes: \n");

  scanf("%d", &minutes);

  printf("Amount of minutes is %d. \n", minutes);

  minToYr = (double)minutes;
  years = minToYr * (1.90259e-6);

  days = years *365;

  printf("Amount of days is %.2f. \nAmount of years is %.2f.\n", days , years);


  return 0;
}

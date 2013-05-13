#include <stdio.h>
#include "clempel.h"

void print_output(short *tab)
{
  while (*tab != -1)
    {
      printf("<%d>", *tab);
      tab++;
    }
  printf("\n");
}

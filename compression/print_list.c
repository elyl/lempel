#include <stdio.h>
#include "clempel.h"

void print_list(t_list *st)
{
  while (st != NULL)
    {
      printf("<%d>%s\n", st->code, st->str);
      st = st->next;
    }
}

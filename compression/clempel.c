#include <stdlib.h>
#include "clempel.h"

void clempel(char *str)
{
  t_list	*st;
  t_list	*tmp;
  
  st = NULL;
  st = add_to_list("toto", st);
  add_to_list("titi", st);
  add_to_list("tutu", st);
  add_to_list("tata", st);
  print_list(st);
  tmp = get_from_list("tutu", st);
  printf("\n<%d>%s\n", tmp->code, tmp->str);
  free_list(st);
}

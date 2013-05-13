#include <stdlib.h>
#include "clempel.h"

void clempel(char *str)
{
  t_list	*st;
  
  st = NULL;
  st = add_to_list("toto", st);
  add_to_list("titi", st);
  add_to_list("tutu", st);
  add_to_list("tata", st);
  print_list(st);
  free_list(st);
}

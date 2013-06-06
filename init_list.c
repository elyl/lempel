#include <stdlib.h>
#include "lzw.h"

t_list *init_list()
{
  t_list	*st;
  unsigned char i;
  char		tmp[2];

  st = NULL;
  i = 0;
  tmp[1] = '\0';
  tmp[0] = i++;
  st = add_to_list(&tmp[0], st);
  while (i < 128)
    {
      tmp[0] = i++;
      add_to_list(&tmp[0], st);
    }
  return (st);
}

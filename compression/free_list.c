#include <stdlib.h>
#include "clempel.h"

void free_list(t_list *st)
{
  t_list	*temp;
  
  while (st != NULL)
    {
      temp = st;
      st = st->next;
      free(temp->str);
      free(temp);
    }
}

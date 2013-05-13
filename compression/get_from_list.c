#include <string.h>
#include "clempel.h"

t_list *get_from_list(char *str, t_list *st)
{
  while (st != NULL)
    {
      if (strcmp(str, st->str) == 0)
	return (st);
      st = st->next;
    }
  return (NULL);
}

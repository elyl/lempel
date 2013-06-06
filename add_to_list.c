#include <stdlib.h>
#include <string.h>
#include "lzw.h"

t_list *add_to_list(unsigned char *str, t_list *st)
{
  static int	code = 0;
  t_list	*tmp;

  tmp = NULL;
  while (st != NULL)
    {
      tmp = st;
      st = st->next;
    }
  st = malloc(sizeof(t_list));
  st->code = code++;
  st->str = malloc((strlen(str) + 1) * sizeof(char));
  strcpy(st->str, str);
  st->next = NULL;
  if (tmp != NULL)
    tmp->next = st;
  return (st);
}

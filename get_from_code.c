#include <unistd.h>
#include "lzw.h"

t_list *get_from_code(unsigned int code, t_list *st)
{
  while (st != NULL && st->code != code)
    st = st->next;
  return (st);
}

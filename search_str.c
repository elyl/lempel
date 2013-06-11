#include <stdlib.h>
#include "lzw.h"

t_elem *search_str(unsigned char c, int code, t_enc *ctx)
{
  t_elem	*tmp;

  if (code == 0)
    return (&ctx->dict[c]);
  tmp = ctx->dict[code].child;
  while (tmp != NULL)
    {
      if (tmp->c == c)
	return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}

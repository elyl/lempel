#include <stdlib.h>
#include "lzw.h"

void init_enc(t_enc *ctx)
{
  int	i;

  ctx->code = 259;
  ctx->nbits = 8;
  i = 0;
  while (i < 256)
    {
      printf("%d\n", i);
      ctx->dict[i].prev = CODE_NULL;
      ctx->dict[i].next = NULL;
      ctx->dict[i].child = NULL;
      ctx->dict[i].c = i;
      i++;
    }
}

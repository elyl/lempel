#include <stdlib.h>
#include "lzw.h"

void init_enc(t_enc *ctx)
{
  int	i;

  ctx->code = 259;
  ctx->nbits = 8;
  ctx->bb.n = 0;
  i = 0;
  while (i < 256)
    {
      ctx->dict[i].prev = CODE_NULL;
      ctx->dict[i].next = NULL;
      ctx->dict[i].child = NULL;
      ctx->dict[i].c = i;
      ctx->dict[i].code = i;
      i++;
    }
}

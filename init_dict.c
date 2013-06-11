#include "lzw.h"

void init_dict(t_enc *ctx)
{
  unsigned char	i;

  i = 0;
  while (i < 128)
    {
      ctx->dict[i].c = i;
      ctx->dict[i].code = i++;
    }
}

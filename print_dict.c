#include <stdio.h>
#include "lzw.h"

void print_dict(t_enc *ctx)
{
  unsigned int	i;

  i = 0;
  while (i < ctx->code_max)
    {
      printf("code: %d, char: %c\n", ctx->dict[i].code, ctx->dict[i].c);
      i++;
    }
}

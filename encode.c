#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "lzw.h"

void encode(t_enc *ctx)
{
  char			str[BUFFER_SIZE];
  int			size;
  int			i;
  t_elem		*tmp;
  
  init_enc(ctx);
  while ((size = read(ctx->fin, &str[0], BUFFER_SIZE)))
    {
      i = 0;
      while (i < size)
	{
	  tmp = search_str(str[i], ctx->code, ctx);
	  if (tmp == NULL)
	    {
	      write_bits(ctx, ctx->code, ctx->nbits);
	      add_str(str[i], ctx->code, ctx);
	      ctx->code = str[i];	     
	    }
	  else
	    ctx->code = tmp->code;
	  if (ctx->code_max == (1 << ctx->nbits))
	    ctx->code_max++;
	  i++;
	}
    }
}

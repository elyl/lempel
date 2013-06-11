#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "lzw.h"

void encode(t_enc *ctx)
{
  unsigned char		w[BUFFER_SIZE];
  unsigned char		wc[BUFFER_SIZE];
  char			str[BUFFER_SIZE];
  int			size;
  int			i;
  int			code;
  t_elem		*tmp;
  
  code = 0;
  init_enc(ctx);
  while ((size = read(ctx->fin, &str[0], BUFFER_SIZE)))
    {
      i = 0;
      while (i < size)
	{
	  tmp = search_str(str[i], code, ctx);
	  if (ctx->code == (1 << ctx->nbits))
	    ctx->code++;
	  i++;
	}
    }
}

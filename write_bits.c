#include <unistd.h>
#include "lzw.h"

void write_bits(t_enc *ctx, unsigned int code, int nbits)
{
  unsigned int	pos;
  unsigned char buffer[256];

  pos = 0;
  ctx->bb.buf = ((ctx->bb.buf >> nbits) | (code & ((1 << nbits) - 1)));
  nbits += ctx->bb.n;
  while (nbits >= 8)
    {
      nbits -= 8;
      buffer[pos++] = ctx->bb.buf >> nbits;
      if (pos == sizeof(buffer))
	write(ctx->fout, &buffer[0], pos);
    }
  ctx->bb.n = nbits;
}

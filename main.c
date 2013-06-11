#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "lzw.h"

int main(int argc, char **argv)
{
  t_enc	*ctx;

  ctx = malloc(sizeof(t_enc));
  if (argc < 4)
    {
      free(ctx);
      printf("Missing argument\n");
      return (-1);
    }
  ctx->fin = open(argv[2], O_RDONLY);
  if (ctx->fin == -1)
    {
      free(ctx);
      printf("Can't open file %s\n", argv[2]);
      return (-2);
    }
  ctx->fout = open(argv[3], O_WRONLY | (O_CREAT & ~S_IRWXU));
  if (ctx->fout == -1)
    {
      printf("Can't open file %s\n", argv[3]);
      free(ctx);
      return (-3);
    }
  if (argv[1][0] == 'c')
    encode(ctx);
  else
    decode(ctx);
  close(ctx->fin);
  close(ctx->fout);
  free(ctx);
  return (1);
}

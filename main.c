#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "lzw.h"

int main(int argc, char **argv)
{
  int	fin;
  int	fout;

  if (argc < 4)
    {
      printf("Missing argument\n");
      return (-1);
    }
  fin = open(argv[2], O_RDONLY);
  if (fin == -1)
    {
      printf("Can't open file %s\n", argv[2]);
      return (-2);
    }
  fout = open(argv[3], O_WRONLY | O_CREAT);
  if (fout == -1)
    {
      printf("Can't open file %s\n", argv[3]);
      return (-3);
    }
  if (argv[1][0] == 'c')
    encode(fin, fout);
  else
    decode(fin, fout);
  close(fin);
  close(fout);
  return (1);
}

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "clempel.h"

void encode(int fin, int fout)
{
  t_list	*st;
  t_list	*tmp;
  char		w[255];
  char		wc[255];
  char		*str;
  
  str = malloc(256);
  read(fin, str, 255);
  str[255] = '\0';
  st = init_list();
  w[0] = '\0';
  while (*str)
    {
      strcpy(&wc[0], &w[0]);
      strncat(&wc[0], str, 1);
      tmp = get_from_list(&wc[0], st);
      if (tmp != NULL)
	strcpy(&w[0], &wc[0]);
      else
	{
	  add_to_list(&wc[0], st);
	  w[0] = *str;
	  w[1] = '\0';
	  tmp = get_from_list(&wc[0], st);
	  write(fout, &tmp->code, 1);
	}
      str++;
    }
  tmp = get_from_list(&w[0], st);
  write(fout, &tmp->code, 1);
  print_list(st);
  free_list(st);
}

#include <stdlib.h>
#include <string.h>
#include "clempel.h"

void clempel(char *str)
{
  t_list	*st;
  t_list	*tmp;
  char		w[255];
  char		wc[255];
  char		c;
  
  st = init_list();
  w[0] = '\0';
  while (*str)
    {
      strncpy(&c, str, 1);
      strcpy(&wc[0], &w[0]);
      strncat(&wc[0], str, 1);
      tmp = get_from_list(&wc[0], st);
      if (tmp != NULL)
	strcpy(&w[0], &wc[0]);
      else
	{
	  add_to_list(&wc[0], st);
	  strncpy(&w[0], str, 1);
	  w[1] = '\0';
	}
      str++;
    }
  print_list(st);
  free_list(st);
}

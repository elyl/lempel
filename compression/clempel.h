#ifndef __CLEMPEL_H__
#define __CLEMPEL_H__

#define FIRST_CODE 259


typedef struct s_list
{
  int		code;
  char		*str;
  struct s_list	*next;
}	t_list;

void	free_list(t_list *st);
void	print_list(t_list *st);
void	clempel(char *str);

t_list	*add_to_list(char *str, t_list *st);
t_list	*get_from_list(char *str);

#endif

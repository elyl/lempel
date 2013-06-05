#ifndef __CLEMPEL_H__
#define __CLEMPEL_H__

typedef struct s_list
{
  unsigned char		code;
  unsigned char		*str;
  struct s_list	*next;
}	t_list;

void	free_list(t_list *st);
void	print_list(t_list *st);
void	print_output(short *tab);
void	lzw(char *str);
void	encode(int fin, int fout);
void	decode(int fin, int fout);

t_list	*init_list();
t_list	*add_to_list(char *str, t_list *st);
t_list	*get_from_list(char *str, t_list *st);

#endif

#ifndef __LZW_H__
#define __LZW_H__

#define BUFFER_SIZE	255
#define DICT_SIZE	(1 << 20)
#define HASH_SIZE	DICT_SIZE
#define CODE_NULL	DICT_SIZE

typedef struct s_bitbuffer
{
  unsigned int	buf;
  unsigned int	n;
}	t_bitbuffer;

typedef struct s_elem
{
  unsigned int	prev;
  struct s_elem	*next;
  struct s_elem *child;
  unsigned char	c;
  unsigned int code;
}	t_elem;

typedef struct s_enc
{
  t_bitbuffer	bb;
  unsigned int	code_max;
  int		code;
  int		fin;
  int		fout;
  unsigned int	nbits;
  t_elem	dict[DICT_SIZE];
}	t_enc;

void		encode(t_enc *ctx);
void		decode(t_enc *ctx);
void		init_enc(t_enc *ctx);
void		add_str(unsigned char c, int code, t_enc *ctx);
void		write_bits(t_enc *ctx, unsigned int code, int nbits);
void		print_dict(t_enc *ctx);

t_elem		*search_str(unsigned char c, int code, t_enc *ctx);

#endif

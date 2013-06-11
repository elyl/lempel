#include <stdlib.h>
#include "lzw.h"

void add_str(unsigned char c, int code, t_enc *ctx)
{
  t_elem	*tmp;

  tmp = ctx->dict[code].child;
  ctx->dict[code].child = &ctx->dict[ctx->code_max];
  ctx->dict[code].child->next = tmp;
  ctx->dict[code].child->c = c;
  ctx->dict[code].child->prev = code;
  ctx->dict[code].child->child = NULL;
  ctx->dict[code].child->code = ctx->code_max++;
}

#ifndef _CHUNK_H_
#define _CHUNK_H_

#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <assert.h>
#include "buffer.h"

typedef struct {
	const unsigned char *data;
	int len;
	int alloc;
} chunk;

static inline void chunk_free(chunk *c)
{
	if (c->alloc)
		free((char *)c->data);

	c->data = NULL;
	c->alloc = 0;
	c->len = 0;
}

static inline void chunk_ltrim(chunk *c)
{
	assert(!c->alloc);

	while (c->len && isspace(c->data[0])) {
		c->data++;
		c->len--;
	}
}

static inline void chunk_rtrim(chunk *c)
{
	while (c->len > 0) {
		if (!isspace(c->data[c->len - 1]))
			break;

		c->len--;
	}
}

static inline void chunk_trim(chunk *c)
{
	chunk_ltrim(c);
	chunk_rtrim(c);
}

static inline int chunk_strchr(chunk *ch, int c, int offset)
{
	const unsigned char *p = memchr(ch->data + offset, c, ch->len - offset);
	return p ? (int)(p - ch->data) : ch->len;
}

static inline unsigned char *chunk_to_cstr(chunk *c)
{
	unsigned char *str;

	str = malloc(c->len + 1);
	memcpy(str, c->data, c->len);
	str[c->len] = 0;

	return str;
}

static inline chunk chunk_literal(const char *data)
{
	chunk c = {(const unsigned char *)data, data ? strlen(data) : 0, 0};
	return c;
}

static inline chunk chunk_dup(const chunk *ch, int pos, int len)
{
	chunk c = {ch->data + pos, len, 0};
	return c;
}

static inline chunk chunk_buf_detach(strbuf *buf)
{
	chunk c;

	c.len = buf->size;
	c.data = strbuf_detach(buf);
	c.alloc = 1;

	return c;
}

#endif

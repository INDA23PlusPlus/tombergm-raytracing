#ifndef TEX_H
#define TEX_H

#include <stddef.h>
#include "vec.h"

typedef struct tex_struct	tex_t;

struct tex_struct
{
	int	w;
	int	h;
	void *	c;
	void *	n;
	void *	r;
};

static inline int tex_has_n(const tex_t *tex)
{
	return tex->n != NULL;
}

static inline int tex_has_r(const tex_t *tex)
{
	return tex->r != NULL;
}

int	tex_load_c(tex_t *tex, const char *filename);
int	tex_load_n(tex_t *tex, const char *filename);
int	tex_load_r(tex_t *tex, const char *filename);
void	tex_dstr(tex_t *tex);
vec3_t	tex_sample_buf(const tex_t *tex, const vec2_t *uv, void *buf);
void	tex_sample(	const tex_t *tex, const vec2_t *uv,
			vec3_t *c, vec3_t *n, real_t *r);

#endif

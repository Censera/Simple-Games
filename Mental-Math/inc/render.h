#ifndef	REND_H_
#	define	REND_H_

#	include	"celib.h"
#	include	"init.h"

void	draw_eq(Eq *e, Font f);
void	bubble(Font f, const char *text, Vector2 position, u8 circle_size, u8 border_radius);
u8	draw_numkeys(Style *s, NumKey *k);
void	draw_guess(Style *s, NumKey *k, Eq *e);

#endif

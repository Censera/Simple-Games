#ifndef	INIT_H_
#	define	INIT_H_

#	include	<raylib.h>
#	include	"raygui.h"
#	include	"celib.h"
#	include	"init.h"

#	define	MAX_SLOTS	4

typedef	struct
{
	u8	number[MAX_SLOTS];
	u16	result;
	u16	guess;
	u8	length;
} Eq;

typedef	struct
{
	Font	font;
	Color	color;
	f32	size;
	f32	radius;

}	Style;

typedef	struct
{
	u8	key_number;
	u8	click_position;
	f32	circle_radius;
	f32	border_width;
	f32	extera_width;
	f32	gap;
}	NumKey;

void	gen_eq(Eq *e);
void	init_numkey(NumKey *k);
void	init_style(Style *s);

#endif

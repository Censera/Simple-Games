#ifndef	INIT_H_
#	define	INIT_H_

#	include	<raylib.h>
#	include	"celib.h"
#	include	"init.h"

typedef	struct
{
	u8	p;
	u8	current_face;
}	Prop;

typedef	enum
{
	COIN,
	DICE
}	Mode;

void	choose_mode(Mode *m);

void	init_coin(Prop *c);
void	init_dice(Prop *d);

#endif

#	include	"inc/init.h"
#	include	"inc/font/font.h"

void	choose_mode(Mode *m)
{
	if (IsKeyPressed(KEY_ENTER) && *m == COIN)	*m = DICE;
	else
	if (IsKeyPressed(KEY_ENTER) && *m == DICE)	*m = COIN;
}

void	init_coin(Prop *c)
{
	c->p = 2;
	c->current_face = 1;
}

void	init_dice(Prop *d)
{
	d->p = 6;
	d->current_face = 1;
}

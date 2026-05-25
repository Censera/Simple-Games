#	include	"inc/logic.h"

void	randomize(Prop **p, Mode *m) { *m == COIN ? flip_coin(p[0]) : roll_dice(p[1]); }

void	flip_coin(Prop *c) { c->current_face = ce_random(1, 2); };
void	roll_dice(Prop *d) { d->current_face = ce_random(1, 6); };

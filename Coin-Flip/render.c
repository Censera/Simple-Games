#	include	"inc/render.h"


void	draw(Prop **p, Mode *m, Font f)
{
	if (*m == COIN)
		draw_coin(p[0]);
	else
		draw_dice(p[1], f);
}

void	draw_coin(Prop *c)
{
        DrawText(TextFormat("%i", c->current_face), 450, 300, 100, GREEN);
}

void	draw_dice(Prop *d, Font f)
{
	DrawTextEx(f, TextFormat("%i", d->current_face), (Vector2) { 450, 300, }, 100, 1, RED);
}

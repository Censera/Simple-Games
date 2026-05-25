#	include	"inc/init.h"
#	include	"inc/font/font.h"

void	gen_eq(Eq *e)
{
	u8	i;

	i = 0;
	e->result = 0;
	e->guess = 255;
	do
	{
		e->length = ce_random(2, MAX_SLOTS);
		e->number[i] = (u8)ce_random(1, 20);
		e->result += e->number[i];
		i++;
	} while (i < e->length);
}

void	init_style(Style *s)
{
	s->font = LoadFontFromMemory(".ttf", font_ttf, font_ttf_len, 46, NULL, 0);

	GuiSetFont(s->font);

	GuiSetStyle(BUTTON, BORDER_COLOR_NORMAL, 0x000000FF);
	GuiSetStyle(BUTTON, BASE_COLOR_NORMAL, 0xFFFFFFFF);
	GuiSetStyle(BUTTON, TEXT_COLOR_NORMAL, 0x000000FF);
}

void	init_numkey(NumKey *k)
{
	k->circle_radius = 20.0f;
	k->border_width = 4.0f;
	k->extera_width = k->border_width + 5.0f;
	k->gap = k->circle_radius + k->extera_width + 10.0f;

	k->key_number = 1;
	k->click_position = k->key_number;
}

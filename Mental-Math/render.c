#	include	"inc/render.h"

void	draw_eq(Eq *e, Font f)
{
	Rectangle	rec = { 0 };
	Vector2	position = { 0 };
	u16	full_length;
	u8	radius;
	u8	gap;
	u8	i;

	radius = 30;
	gap = radius + 5;

	i = 0;
	full_length = 0;
	while (i < e->length)
	{
		full_length += 2 * (radius + gap);

		i++;
	}

	position = (Vector2)
	{
		GetScreenWidth() / 2 - full_length / 2,
		GetScreenHeight() / 2
	};

	DrawText(TextFormat("%d", full_length), 200, 30, 30, BLACK);

	rec = (Rectangle)
	{
		position.x,
		position.y,
		radius + gap,
		radius
	};

	i = 0;
	while (i < e->length)
	{
		rec.x = position.x + 2 * rec.width * i;

		bubble(f, TextFormat("%i", e->number[i]), (Vector2) { rec.x, rec.y }, radius, 4);

		i++;
	}

	rec = (Rectangle)
	{
		position.x,
		position.y,
		radius + gap,
		radius
	};

	i = 0;
	while (i < e->length)
	{
		rec.x = (position.x + rec.width) + 2 * rec.width * i;

		if (i < e->length - 1)
			bubble(f, "+", (Vector2) { rec.x, rec.y }, radius - 10, 4);
		else
			bubble(f, "=", (Vector2) { rec.x, rec.y }, radius - 10, 4);

		i++;
	}

	rec.x = position.x + 2 * rec.width * i;
	bubble(f, "?", (Vector2) { rec.x, rec.y }, radius, 4);

	return;
}

void	bubble(Font f, const char *text, Vector2 position, u8 circle_size, u8 border_radius)
{
	Vector2	text_size = MeasureTextEx(f, text, 26, 1);

	DrawCircleV
	(
		(Vector2) { position.x, position.y + border_radius },
 		circle_size + border_radius,
		RED
	);

	DrawRing(position, circle_size, circle_size + border_radius, 0, 360, 1, RED);
	DrawCircleV(position, circle_size, WHITE);

	Vector2	center =
	{
		position.x - text_size.x / 2,
		position.y - text_size.y / 2,
	};

	DrawTextEx(f, text, center, 26, 1, BLACK);
}

u8	draw_numkeys(Style *s, NumKey *k)
{
	init_numkey(k);
	Vector2	position = { 0 };
	Vector2	zero_key = { 0 };
	Vector2	del_key = { 0 };
	Vector2	screen;

	Vector2	mouse_pos = GetMousePosition();

	screen = (Vector2) { GetScreenWidth(), GetScreenHeight() };
	for (u8 i = 0; i < 3; i++)
	{
		position.y = i * (k->circle_radius + k->gap) + screen.y / 2 + 100.0f;

		for (u8 j = 0; j < 3; j++)
		{
			position.x = j * (k->circle_radius + k->gap)
			+ screen.x / 2.0f - (k->circle_radius + k->gap) * 1.5f;

			if (IsMouseButtonPressed(0))
			{
				if (CheckCollisionPointCircle(mouse_pos, position,
					k->circle_radius))	k->click_position = k->key_number;
			}

			bubble
			(
				s->font,
				TextFormat("%i", k->key_number++),
				position,
				k->circle_radius,
				k->border_width
			);

		}
	}

	position = (Vector2)
	{
		screen.x / 2.0f - (k->circle_radius + k->gap) * 1.5f,
		screen.y / 2.0f + 100.0f
	};

	zero_key = (Vector2)
	{
		position.x + (k->circle_radius + k->gap),
		position.y + (k->circle_radius + k->gap) * 3.0f
	};

	del_key = (Vector2)
	{
		position.x + (k->circle_radius + k->gap) * 3.0f,
		position.y
	};

	bubble
	(
		s->font, "x",
		del_key,
		k->circle_radius,
		k->border_width
	);

	bubble
	(
		s->font,
		TextFormat("%i", k->click_position),
		(Vector2)
		{
			position.x + (k->circle_radius + k->gap) * 4.0f,
			position.y
		},
		k->circle_radius,
		k->border_width
	);

	bubble
	(
		s->font,
 		"0",
		zero_key,
		k->circle_radius,
		k->border_width
	);

	if (IsMouseButtonPressed(0))
	{

		if (CheckCollisionPointCircle(mouse_pos, zero_key,
			k->circle_radius))	k->click_position = 0;

		if (CheckCollisionPointCircle(mouse_pos, del_key,
			k->circle_radius))	k->click_position = 10;
	}

	return k->click_position;
}


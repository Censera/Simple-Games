#	include	<raylib.h>

#	include	"inc/init.h"
#	include	"inc/logic.h"
#	include	"inc/render.h"

int main(void)
{
	SetConfigFlags(FLAG_MSAA_4X_HINT);
	SetConfigFlags(FLAG_VSYNC_HINT);
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);

	const u16	width = 900;
	const u16	height = 600;

	InitWindow(width, height, "Flip A Coin");
	SetTargetFPS(60);

	Font	font = LoadFont("res/Dice.tff");

	Prop	coin = {0};
	Prop	dice = {0};

	init_coin(&coin);
	init_dice(&dice);

	Prop	*props[2] = {&coin, &dice};

	Mode	mode = COIN;
	while (!WindowShouldClose())
	{
		choose_mode(&mode);
		if (IsKeyPressed(KEY_SPACE))
			randomize(props, &mode);

		BeginDrawing();

			ClearBackground(WHITE);
			draw(props, &mode, font);

		EndDrawing();
	}

	UnloadFont(font);
	CloseWindow();
	return (0);
}

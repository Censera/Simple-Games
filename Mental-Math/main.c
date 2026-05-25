#	include	<raylib.h>
#	include	<stdio.h>
#	include	"inc/init.h"
#	include	"inc/render.h"

int	main(void)
{
	SetConfigFlags(FLAG_MSAA_4X_HINT);
	SetConfigFlags(FLAG_VSYNC_HINT);
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);

	InitWindow(900, 600, "Math");

	SetTargetFPS(60);

	Style style = { 0 };
	init_style(&style);

	NumKey numkeys;
	init_numkey(&numkeys);

	Eq	equation = { 0 };
	gen_eq(&equation);

	while (!WindowShouldClose())
	{
		BeginDrawing();
			ClearBackground(WHITE);

			draw_guess(&style, &numkeys, &equation);
			equation.guess = draw_numkeys(&style, &numkeys);

			DrawText(TextFormat("%d", equation.guess), 200, 20, 30, RED);

			if (GuiButton((Rectangle)
			{
				100,
				GetScreenHeight() - 100,
				200,
				40
			}, "GEN"))
			{
				gen_eq(&equation);
			}

			DrawText(TextFormat("length: %d", equation.length), 20, 20, 40, BLACK);

		EndDrawing();
	}

	CloseWindow();
	return (0);
}

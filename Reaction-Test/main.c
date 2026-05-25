#	include	<raylib.h>
#	include	"time.h"
#	include	"inc/celib.h"

int	main(void)
{
	InitWindow(1200.0f, 800.0f, "..");

	while (!WindowShouldClose())
	{
		BeginDrawing();

			ClearBackground(WHITE);

		EndDrawing();
	}

	CloseWindow();
	return (0);
}


#include "main.h"


int main()
{
	srand((unsigned int)time(NULL));

	/* -- VARIABLES -- */

	//Key input arrays
	bool KeyPressed[NBKEYS] = { 0 };
	bool KeyHolded[NBKEYS] = { 0 };

	//Sfml setup
	sfVideoMode mode = { 800, 600, 32 };
	sfRenderWindow* window;
	sfEvent event;
	sfClock* clock = sfClock_create();
	// Time in milliseconds
	float runtime = 0;
	// Delta time
	float dt = 0;

	//Create the main window
	window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);
	if (!window)
		return EXIT_FAILURE;

	//Load a sprite to display
	hSprite sprite = { { 20,15 },"sprite.png" };
	setupSprite(&sprite);

	//Create a graphical text to display
	hFont font = { 50, "arial.ttf" };
	hText text = { { 0,0 }, "Hello SFML", &font };
	setupText(&text);

	/* -- GAME LOOP -- */
	while (sfRenderWindow_isOpen(window))
	{
		// -- EVENTS
		while (sfRenderWindow_pollEvent(window, &event))
		{
			//Close window : exit
			if (event.type == sfEvtClosed)sfRenderWindow_close(window);
		}

		handleKeyboardKey(sfKeySpace, SPACE, KeyPressed, KeyHolded);


		// -- UPDATE
		{
			float elapsed = sfTime_asMicroseconds(sfClock_getElapsedTime(clock)) / 1000.f;
			dt = elapsed - runtime;
			runtime = elapsed;
		}

		{
			int s = (int)(runtime / 1000.f);
			int ms = (int)(runtime - s * 1000);
			setText(&text, stri(stri("Time : ", s, "s").str,ms,"ms").str);
		}


		// -- DRAW

		sfRenderWindow_clear(window, sfBlack);


		//Draw the sprite
		drawSprite(window, sprite, vec(KeyHolded[SPACE] * cos(toRad(runtime + cos(toRad(runtime)*30))) * 100 + 200, KeyHolded[SPACE] * sin(toRad(runtime+cos(toRad(runtime))*100)) * 100 + 200), runtime, vec(1, 1));
		//Draw the text
		drawText(window, text, vec(0, 0), 0.f, vec(1, 1));


		sfRenderWindow_display(window);
	}

	//Cleanup resources
	destroyText(&text);
	destroySprite(&sprite);
	sfRenderWindow_destroy(window);

	return EXIT_SUCCESS;
}
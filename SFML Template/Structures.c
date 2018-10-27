#include <string.h>
#include <stdio.h>

#include "Structures.h"
#include "Vectors.h"

// - Structure handlers

//Setup
void setupFont(hFont* font)
{
	if (!font->isSetup)
	{
		char path[STRLEN] = pathFONT;
		strcat(path, font->path.str);
		font->font = sfFont_createFromFile(path);
		font->isSetup = !font ? false : true;
	}
}

void setupText(hText* text)
{
	if (!text->font->isSetup)
	{
		setupFont(text->font);
	}
	if (!text->isSetup)
	{
		text->text = sfText_create();
		sfText_setString(text->text, text->str.str);
		sfText_setFont(text->text, text->font->font);
		sfText_setCharacterSize(text->text, text->font->size);
		text->isSetup = true;
	}
}

void setupSprite(hSprite* sprite)
{
	if (!sprite->isSetup)
	{
		char path[STRLEN] = pathTEXTURE;
		strcat(path, sprite->path.str);
		sprite->texture = sfTexture_createFromFile(path, NULL);
		sprite->sprite = sfSprite_create();
		sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
		sfSprite_setOrigin(sprite->sprite, vec(sprite->hotspot.x, sprite->hotspot.y));
		sprite->isSetup = !sprite->texture ? false : true;
	}
}

void setupActor(hActor* actor)
{

}

void setupActorText(hActorText* actorText)
{
	if (!actorText->text->isSetup)
	{
		setupText(actorText->text);
	}
	if (!actorText->isSetup)
	{
		actorText->isSetup = true;
	}
}

void setupActorSprite(hActorSprite* actorSprite)
{
	if (!actorSprite->sprite->isSetup)
	{
		setupSprite(actorSprite->sprite);
	}
	if (!actorSprite->isSetup)
	{
		actorSprite->isSetup = true;
	}
}


//Draw
void drawText(sfRenderWindow* renderWindow, hText text, sfVector2f position, float angle, sfVector2f scale)
{
	sfText_setPosition(text.text, position);
	sfText_setRotation(text.text, angle);
	sfText_setScale(text.text, vecMulFloat(scale, SCREENSCALE));
	sfRenderWindow_drawText(renderWindow, text.text, NULL);
}

void drawSprite(sfRenderWindow* renderWindow, hSprite sprite, sfVector2f position, float angle, sfVector2f scale)
{
	sfSprite_setPosition(sprite.sprite, position);
	sfSprite_setRotation(sprite.sprite, angle);
	sfSprite_setScale(sprite.sprite, vecMulFloat(scale, SCREENSCALE));
	sfRenderWindow_drawSprite(renderWindow, sprite.sprite, NULL);
}

void drawActorText(sfRenderWindow* renderWindow, hActorText actorText)
{
	drawText(renderWindow, *actorText.text, actorText.actor->position, actorText.actor->rotation, actorText.actor->scale);
}

void drawActorSprite(sfRenderWindow* renderWindow, hActorSprite actorSprite)
{
	drawSprite(renderWindow, *actorSprite.sprite, actorSprite.actor->position, actorSprite.actor->rotation, actorSprite.actor->scale);
}


//Destroy
void destroyFont(hFont* font)
{
	if (font->isSetup)
	{
		sfFont_destroy(font->font);
		font->isSetup = false;
	}
}

void destroyText(hText* text)
{
	if (text->font->isSetup)
	{
		destroyFont(text->font);
	}
	if (text->isSetup)
	{
		sfText_destroy(text->text);
		text->isSetup = false;
	}
}

void destroySprite(hSprite* sprite)
{
	if (sprite->isSetup)
	{
		sfSprite_destroy(sprite->sprite);
		sfTexture_destroy(sprite->texture);
		sprite->isSetup = false;
	}
}

void destroyActor(hActor* actor)
{

}

void destroyActorText(hActorText* actorText)
{
	if (actorText->text->isSetup)
	{
		destroyText(actorText->text);
	}
	if (actorText->isSetup)
	{
		actorText->isSetup = false;
	}
}

void destroyActorSprite(hActorSprite* actorSprite)
{
	if (actorSprite->sprite->isSetup)
	{
		destroySprite(actorSprite->sprite);
	}
	if (actorSprite->isSetup)
	{
		actorSprite->isSetup = false;
	}
}


// - Utility

void setText(hText* text, char str[STRLEN])
{
	strcpy(text->str.str, str);
	text->isSetup = false;
	setupText(text);
}
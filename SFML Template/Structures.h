#include <SFML/Graphics.h>

#include "Defines.h"
#include "Enums.h"

#ifndef STRUCTURES
#define STRUCTURES

// - Structures

struct S_Str
{
	char str[STRLEN];
};
//char str[STRLEN]
typedef struct S_Str hStr;



struct S_Font
{
	int size;
	hStr path;
	sfFont* font;
	bool isSetup;
};
//int size
//char path[STRLEN]
//sfFont* font
//bool isSetup
typedef struct S_Font hFont;



struct S_Text
{
	sfVector2f hotspot;
	hStr str;
	hFont* font;
	sfText* text;
	bool isSetup;
};
//sfVector2f hotspot
//char str[STRLEN]
//hFont* font
//sfText* text
//bool isSetup
typedef struct S_Text hText;



struct S_Sprite
{
	sfVector2f hotspot;
	hStr path;
	sfTexture* texture;
	sfSprite* sprite;
	bool isSetup;
};
//sfVector2f hotspot
//char path[STRLEN]
//sfTexture* texture
//sfSprite* sprite
//bool isSetup
typedef struct S_Sprite hSprite;



struct S_Actor
{
	sfVector2f position;
	sfVector2f direction;
	float rotation;
	sfVector2f scale;
};
//sfVector2f position
//sfVector2f direction
//float rotation
//sfVector2f scale
typedef struct S_Actor hActor;



struct S_ActorSprite
{
	hActor* actor;
	hSprite* sprite;
	bool isSetup;
};
//hActor* actor
//hSprite* sprite
//bool isSetup
typedef struct S_ActorSprite hActorSprite;



struct S_Player
{
	hActorSprite* actorSprite;
	float move_speed;
	float move_speedMax;
	bool thrust;
};
//hActorSprite* actorSprite
//float move_speed
//float move_speedMax
//bool thrust
typedef struct S_Player hPlayer;



struct S_ActorText
{
	hActor* actor;
	hText* text;
	bool isSetup;
};
//hActor* actor
//hText* text
//bool isSetup
typedef struct S_ActorText hActorText;



// - Structure handlers

//Setup

void setupFont(hFont* font);
void setupText(hText* text);
void setupSprite(hSprite* sprite);
void setupActor(hActor* actor);
void setupActorText(hActorText* actorText);
void setupActorSprite(hActorSprite* actorSprite);


//Draw

void drawText(sfRenderWindow* renderWindow, hText text, sfVector2f position, float angle, sfVector2f scale);
void drawSprite(sfRenderWindow* renderWindow, hSprite sprite, sfVector2f position, float angle, sfVector2f scale);
void drawActorText(sfRenderWindow* renderWindow, hActorText actorText);
void drawActorSprite(sfRenderWindow* renderWindow, hActorSprite actorSprite);


//Destroy

void destroyFont(hFont* font);
void destroyText(hText* text);
void destroySprite(hSprite* sprite);
void destroyActor(hActor* actor);
void destroyActorText(hActorText* actorText);
void destroyActorSprite(hActorSprite* actorSprite);


//Utility

void setText(hText* text, char str[STRLEN]);

#endif//STRUCTURES
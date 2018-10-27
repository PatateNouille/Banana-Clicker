#include <SFML/System/Vector2.h>

#include "Structures.h"

#ifndef VECTORS
#define VECTORS

// - Vectors

sfVector2f vec(float x, float y);
sfVector2f vecPoints(sfVector2f src, sfVector2f dest);
sfVector2f vecMulFloat(sfVector2f vect, float x);
sfVector2f vecMulVec(sfVector2f vect1, sfVector2f vect2);
sfVector2f vecAddFloat(sfVector2f vect, float x);
sfVector2f vecAddVec(sfVector2f vect1, sfVector2f vect2);
sfVector2f vecNormalize(sfVector2f vect);
float vecToAngle(sfVector2f vect);
sfVector2f vecFromAngle(float angle);
float vecLength(sfVector2f vect);

#endif//VECTORS
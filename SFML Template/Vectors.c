#include "Vectors.h"

// - Vectors

//Return a vector with coordinates (x, y)
sfVector2f vec(float x, float y)
{
	sfVector2f vec = { x, y };
	return vec;
}

//Vector from dest to src
sfVector2f vecPoints(sfVector2f src, sfVector2f dest)
{
	return vec(dest.x - src.x, dest.y - src.y);
}

//Multiply both coordinates of a vector by a float
sfVector2f vecMulFloat(sfVector2f vect, float x)
{
	return vec(vect.x * x, vect.y * x);
}

//Multiply a vector by another, x with x and y with y
sfVector2f vecMulVec(sfVector2f vect1, sfVector2f vect2)
{
	return vec(vect1.x * vect2.x, vect1.y * vect2.x);
}

//Add a float to the length of a vector
sfVector2f vecAddFloat(sfVector2f vect, float x)
{
	sfVector2f norm = vecNormalize(vect);
	return vec(vect.x + norm.x*x, vect.y + norm.y*x);
}

//Add a vector to another, x with x and y with y
sfVector2f vecAddVec(sfVector2f vect1, sfVector2f vect2)
{
	return vec(vect1.x + vect2.x, vect1.y + vect2.y);
}

//Return the normalized vector
sfVector2f vecNormalize(sfVector2f vect)
{
	float angle = (vecToAngle(vect) - 90)*PI / 180;
	return vec(cos(angle), sin(angle));
}

//Return angle in degrees from vector [0;360[, 0 is top, clockwise
float vecToAngle(sfVector2f vect)
{
	return (-atan2(vect.x, vect.y) * 180 / PI) + 180;
}

//Return vector from angle in degrees [0;360[, 0 is top, clockwise
sfVector2f vecFromAngle(float angle)
{
	float radAngle = (angle - 90) * PI / 180;
	return  vec(cos(radAngle), sin(radAngle));
}

//Return vector length
float vecLength(sfVector2f vect)
{
	return (float)sqrt(sqr(vect.x) + sqr(vect.y));
}



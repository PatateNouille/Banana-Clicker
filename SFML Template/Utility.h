#include <string.h>
#include <stdio.h>

#include "Defines.h"
#include "Structures.h"

#ifndef UTILITY
#define UTILITY

int sign(float number);

float toDeg(float rad);
float toRad(float deg);

hStr stri(char strStart[], int n, char strEnd[]);
hStr strf(char strStart[], float n, char strEnd[]);

#endif//UTILITY
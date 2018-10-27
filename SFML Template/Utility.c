#include "Utility.h"


//number > 0 : 1
//number == 0 : 0
//numner < 0 : -1
int sign(float number)
{
	return (number > 0) ? 1 : (number < 0) ? -1 : 0;
}

//Turn radians into degrees
float toDeg(float rad)
{
	return rad / PI * 180;
}

//Turn degrees into radians
float toRad(float deg)
{
	return deg / 180 * PI;
}


//Concatenate an int in the middle of two strings
hStr stri(char strStart[], int n, char strEnd[])
{
	hStr str = { "" };
	char strMid[10] = { 0 };
	sprintf(strMid, "%d", n);
	strcat(str.str, strStart);
	strcat(str.str, strMid);
	strcat(str.str, strEnd);
	return str;
}

//Concatenate a float in the middle of two strings
hStr strf(char strStart[], float n, char strEnd[])
{
	hStr str = { "" };
	char strMid[10] = { 0 };
	sprintf(strMid, "%f", n);
	strcat(str.str, strStart);
	strcat(str.str, strMid);
	strcat(str.str, strEnd);
	return str;
}

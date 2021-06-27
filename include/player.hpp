#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

using namespace sf;

//screen size
#define RESX 1024
#define RESY 768

//pi divided by 180
#define PIDBY180 0.0174532925199444

class player
{
private:
	const float accel = 0.2f;
	const float deaccel = 0.1f;
	const float maxspeed = 8.0f;
	const float minspeed = -4.0f;
	const float rotateSpeed = 2.1f;

	float speed = 0.0f;
	float angle = 0.0f;
	double carSin, carCos;

	RectangleShape rec;
	Texture tex;

public:
	void recInit(void);
	void movement(void);

	//getters
	float getAngle(void);
	float getSpeed(void);
	double getSin(void);
	double getCos(void);
	RectangleShape getRec(void);
};

#endif // PLAYER_H_INCLUDED

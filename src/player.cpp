#include "player.hpp"

void player::recInit(void)
{
	tex.loadFromFile("car.png");
	rec.setSize(Vector2f(64, 32));
	rec.setPosition(Vector2f(RESX/2, RESY/2));
	rec.setOrigin(Vector2f(32, 16));
	rec.setTexture(&tex);
}

void player::movement(void)
{
	//sin and cos
	carSin = sin(angle*PIDBY180);
	carCos = cos(angle*PIDBY180);
	rec.setRotation(angle);

	//movement
	if(speed > 0.1f || speed < -0.1f){
		rec.move(carCos*speed, carSin*speed);
		//rotate
		if(Keyboard::isKeyPressed(Keyboard::Left)){
			angle -= speed/rotateSpeed;
		}
		else if(Keyboard::isKeyPressed(Keyboard::Right)){
			angle += speed/rotateSpeed;
		}
	}

	//accel, brake and reverse
	if(Keyboard::isKeyPressed(Keyboard::Up)){
		speed += accel;
	}
	else if(Keyboard::isKeyPressed(Keyboard::Down)){
		speed -= accel;
	}

	//deaccel
	if(speed > 0.0f){
		speed -= deaccel;
	}
	else if(speed < 0.0f){
		speed += deaccel;
	}

	//speed limit
	if(speed > maxspeed){
		speed = maxspeed;
	}
	else if(speed < minspeed){
		speed = minspeed;
	}
}

//getters
float player::getAngle(void)
{
	return angle;
}

float player::getSpeed(void)
{
	return speed;
}

double player::getSin(void)
{
	return carSin;
}

double player::getCos(void)
{
	return carCos;
}

RectangleShape player::getRec(void)
{
	return rec;
}

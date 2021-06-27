/*
Car Movement
By lucassobreiro
27/06/2021
*/

#include "player.hpp"

player Player;
RenderWindow window(VideoMode(RESX, RESY), "Car Movement", Style::Close);

int main()
{
	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);

	Player.recInit();

	//update
	while(window.isOpen())
	{
		Event evt;
		while(window.pollEvent(evt))
		{
			if(evt.type == Event::Closed) window.close();

			if(evt.type == Event::KeyPressed)
			{
				if(evt.key.code == Keyboard::Escape)
					window.close();

				if(evt.key.code == Keyboard::I)
					std::cout<<"Angle: "<<Player.getAngle()<<"\tSin: "
					<<Player.getSin()<<"\tCos: "<<Player.getCos()<<std::endl;

				if(evt.key.code == Keyboard::S)
					std::cout << "Speed: " << Player.getSpeed() << std::endl;
			}
		}
		Player.movement();

		//draw
		window.clear(Color(200, 200, 200));
		window.draw(Player.getRec());
		window.display();
	}

	return 0;
}

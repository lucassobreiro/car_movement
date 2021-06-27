TARGET=car_movement

compile:
	g++ src/*.cpp -c -I include/ -Wall
	g++ *.o -o $(TARGET) -lsfml-graphics -lsfml-window -lsfml-system
run:
	./$(TARGET)
clear:
	rm *.o

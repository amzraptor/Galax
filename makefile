exe:	main.cpp
	g++ *.cpp src/* `sdl-config --cflags --libs` -lSDL_image -lSDL_mixer -lSDL_ttf -Iincludes 

run:
	./a.out

clean:
	rm a.out


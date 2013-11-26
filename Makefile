all:
	g++ cars.cpp -o cars  -lm -lGL -lGLU -lglut

clean:
	rm -f cars

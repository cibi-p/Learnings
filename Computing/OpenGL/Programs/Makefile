simple_program: Simpleprogram_1.c
	gcc `pkg-config --cflags glfw3` -o Bin/simpleProgram1.out Simpleprogram_1.c `pkg-config --static --libs glfw3` glad_source/glad.c
	g++ `pkg-config --cflags glfw3` -o Bin/triangle Triangle.cpp `pkg-config --static --libs glfw3` glad_source/glad.c
	g++ `pkg-config --cflags glfw3` -o Bin/pbo pbo_test.cpp `pkg-config --static --libs glfw3` glad_source/glad.c 

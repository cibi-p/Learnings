texture_main:
	g++ `pkg-config --cflags glfw3` -o texture texture_main.cpp `pkg-config --static --libs glfw3` ../glad_source/glad.c 
single_pbo:
	g++ `pkg-config --cflags glfw3` -o pbotexture texture_main_pbotime.cpp `pkg-config --static --libs glfw3` ../glad_source/glad.c texture_pbo_2tex/timeAnalysisfun.c

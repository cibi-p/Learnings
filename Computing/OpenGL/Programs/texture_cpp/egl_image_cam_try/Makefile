texture_main:
	g++ `pkg-config --cflags glfw3` -o bin/egl_server egl_cam_server.cpp v4l2libstream.c `pkg-config --static --libs glfw3` ./glad_gles/src/glad.c ./glad_egl/src/glad_egl.c -lEGL
	g++ `pkg-config --cflags glfw3` -o bin/egl_client egl_cam_client.cpp v4l2libstream.c `pkg-config --static --libs glfw3` ./glad_gles/src/glad.c ./glad_egl/src/glad_egl.c -lEGL

#include <glad/glad.h> // GLAD: https://github.com/Dav1dde/glad ... GLAD 2 also works via the web-service: https://gen.glad.sh/ (leaving all checkbox options unchecked)
#include <GLFW/glfw3.h>
 
#define STB_IMAGE_IMPLEMENTATION
#include "../../../stb_image.h"
 
#include <iostream>
#include <fstream> // Used in "shader_configure.h" to read the shader text files.
 
#include "shader_configure.h" // Used to create the shaders.
 
unsigned int load_texture_image(const char* file_name); // Function prototype
 
int main()
{
	// (1) GLFW: Initialise & Configure
	// -----------------------------------------
	if (!glfwInit())
		exit(EXIT_FAILURE);
 
	glfwWindowHint(GLFW_SAMPLES, 4); // Anti-aliasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);	
	
	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
 
	int monitor_width = mode->width; // Monitor's width.
	int monitor_height = mode->height;
 
	int window_width = (int)(monitor_width * 0.65f); // Window size will be 50% the monitor's size.
	int window_height = (int)(monitor_height * 0.65f); // Cast is simply to silence the compiler warning.
 
	GLFWwindow* window = glfwCreateWindow(window_width, window_height, "Loading Images - Scrolling Texture Coordinates", NULL, NULL);
	// GLFWwindow* window = glfwCreateWindow(window_width, window_height, "Loading Images – Scrolling Texture Coordinates", glfwGetPrimaryMonitor(), NULL); // Full Screen Mode ("Alt" + "F4" to Exit!)
 
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
 
	glfwMakeContextCurrent(window); // Set the window to be used and then centre that window on the monitor. 
	glfwSetWindowPos(window, (monitor_width - window_width) / 2, (monitor_height - window_height) / 2);
 
	glfwSwapInterval(1); // Set VSync rate 1:1 with monitor's refresh rate.
	
	// (2) GLAD: Load OpenGL Function Pointers
	// -------------------------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) // For GLAD 2 use the following instead: gladLoadGL(glfwGetProcAddress)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
 
	glEnable(GL_MULTISAMPLE); // Anti-aliasing
	glEnable(GL_BLEND); // GL_BLEND for OpenGL transparency which is further set within the fragment shader.
 
	// Source image (1st argument; the one being rendered) = alpha, e.g., 0.45... Destination image (2nd argument; already in the buffer) = 1 - source (1 - 0.45 = 0.55)
	// -------------------------------------------------------------------------------------------------- https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glBlendFunc.xhtml
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
 
	// (3) Compile Shaders Read from Text Files
	// ------------------------------------------------------
	const char* vert_shader = "shader_glsl.vert";
	const char* frag_shader = "shader_glsl.frag";
 
	Shader main_shader(vert_shader, frag_shader);
	main_shader.use();	
 
	// (4) Declare the Rectangle & Triangle Vertex Position & Texture Coordinate Values
	// ----------------------------------------------------------------------------------------------------------
	float scale = 1.0f; // 0.5... To make the rectangle completely fill the display window set this to 1
 
	float rectangle_triangle_vertices[] = // (Typically type: GLfloat is used)
	{
		// Note:  "Being able to store the vertex attributes for that vertex only once is very economical, as a vertex's attribute...
		// data is generally around 32 bytes, while indices are usually 2-4 bytes in size." (Hence, the next tutorial uses: glDrawElements())
		
		// Rectangle vertices (Texture Coordinates: 0,0 = bottom left... 1,1 = top right)
		//-------------------------
		-1.0f * scale, 1.0f * scale, 0.0f,		0.0f, 1.0f,  // left top ......... 0 // Draw this rectangle's six vertices 1st.
		-1.0f * scale, -1.0f * scale, 0.0f,		0.0f, 0.0f,  // left bottom ... 1 // Use NDC coordinates [-1, +1] to completely fill the display window.
		 1.0f * scale, 1.0f * scale, 0.0f,		1.0f, 1.0f,  // right top ....... 2
 
		 1.0f * scale,  1.0f * scale, 0.0f,		1.0f, 1.0f,   // right top ........ 3		
		-1.0f * scale,  -1.0f * scale, 0.0f,	0.0f, 0.0f,  // left bottom ..... 4		
		 1.0f * scale, -1.0f * scale, 0.0f,		1.0f, 0.0f,  // right bottom ... 5
 
		 // Triangle vertices (Drawing this 2nd allows some of the rectangle's fragment colour to be added to this triangle via transparency)
		 // ----------------------
		 0.0f, 0.75f, 0.0f,		0.5f, 1.0f,  // middle top ... 0
		-0.75f, -0.75f, 0.0f,	0.0f, 0.0f,  // left bottom ... 1
		 0.75f,  -0.75f, 0.0f,	1.0f, 0.0f  // right bottom .. 2		 
	};
 
	/* int width, height;
	glfwGetFramebufferSize(window, &width, &height); // Uncomment this block to adjust the effective display area.
	glViewport(-200, -112, int(width + 400), int(height + 225)); */
 
	// (5) Store the Rectangle & Triangle Vertex Data in Buffer Objects Ready for Drawing
	// -------------------------------------------------------------------------------------------------------------
	unsigned int VAO, VBO; // Buffer handles. (Typically type: GLuint is used)	
 
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);	
 
	glBindVertexArray(VAO); // Binding this VAO 1st causes the following VBO to become associated with this VAO.
 
	glBindBuffer(GL_ARRAY_BUFFER, VBO); // ......................... Address operator not required for arrays.
	glBufferData(GL_ARRAY_BUFFER, sizeof(rectangle_triangle_vertices), rectangle_triangle_vertices, GL_STATIC_DRAW);
 
	// Void pointer below is for legacy reasons. Two possible meanings: "offset for buffer objects" & "address for client state arrays"
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0); 
 
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
		   
	glBindVertexArray(0); 	// Unbind VAO
 
	// (6) Load & Bind Image Files & Set Shader's Uniform Samplers
	// --------------------------------------------------------------------------------
	// unsigned int image_1 = load_texture_image("multi_colour_rectangle_mipmaps.jpg");
 
	unsigned int image_1 = load_texture_image("./dryGround.jpeg");
	// unsigned int image_2 = load_texture_image("image_bird_eagle.png");
 
	// unsigned int image_1 = load_texture_image("image_green_leaves.jpg");
	unsigned int image_2 = load_texture_image("insect_image.png");
	
	glActiveTexture(GL_TEXTURE0);	
	glBindTexture(GL_TEXTURE_2D, image_1);
 
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, image_2);
 
	glUniform1i(glGetUniformLocation(main_shader.ID, "image_1"), 0);	
	glUniform1i(glGetUniformLocation(main_shader.ID, "image_2"), 1);
 
	// (7) Optional: Check Maximum Textures Allowed... https://www.khronos.org/opengl/wiki/Shader#Resource_limitations
	// ---------------------------------------------------------------
	GLint max_textures;
	glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, &max_textures);
	std::cout << "The total number of texture image units that can be used (All active programs stages) = " << max_textures << "\n";
	
	glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &max_textures);	
	std::cout << "The maximum number of texture image units that the sampler can use (Fragment shader) = " << max_textures << "\n";
	
	// (8) Enter the Main-Loop
	// --------------------------------
	unsigned int scroll_texture_loc = glGetUniformLocation(main_shader.ID, "scroll_texture");
	float scroll_horizontally = 0.9;
	float scroll_vertically = 0;
	int direction_x = 1;
	int direction_y = 1;
 
	while (!glfwWindowShouldClose(window)) // Main-Loop
	{
		// (9) Scroll Values Used to Scroll the Image in Fragment Shader
		// --------------------------------------------------------------------------------
		//scroll_horizontally += (1.0f / 100.0f) * direction_x;
		//scroll_vertically += (1.0f / 100.0f) * direction_y;
 
		if (std::abs(scroll_horizontally) > 0.9f) // For: 1 / 120, then 0.5 (not 1, because of std::abs) = Direction changes every 2 seconds for 60Hz monitor.
			direction_x = -direction_x;
 
		if (std::abs(scroll_vertically) > 0.9f)
			direction_y = -direction_y;
 
		glUniform2f(scroll_texture_loc, scroll_horizontally, scroll_vertically); // Pass scroll values to fragment shader.
 
		// (10) Clear the Screen & Draw Both Shapes
		// --------------------------------------------------------
		glClearColor(0.35f, 0.6f, 0.8f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
 
		glBindVertexArray(VAO); // Not necessary for this simple case of using only one VAO. Although, it's being unbound at initialisation just above.
		glDrawArrays(GL_TRIANGLES, 0, sizeof(rectangle_triangle_vertices) / sizeof(rectangle_triangle_vertices[0]));
		glBindVertexArray(0);
 
		glfwSwapBuffers(window);
		glfwPollEvents();		
	}
 
	// (11) Exit the Application
	// --------------------------------
	glDeleteProgram(main_shader.ID); // This OpenGL function call is talked about in: shader_configure.h
 
	/* glfwDestroyWindow(window) // Call this function to destroy a specific window */	
	glfwTerminate(); // Destroys all remaining windows and cursors, restores modified gamma ramps, and frees resources.
 
	exit(EXIT_SUCCESS); // Function call: exit() is a C/C++ function that performs various tasks to help clean up resources.
}
 
unsigned int load_texture_image(const char* file_name)
{
	stbi_set_flip_vertically_on_load(1); // Without calling this function, the image is upside-down.
 
	int width, height, num_components;		
	unsigned char* image_data = stbi_load(file_name, &width, &height, &num_components, 0);
 
	unsigned int textureID;
	glGenTextures(1, &textureID);
 
	if (image_data)
	{
		GLenum format{};
 
		if (num_components == 1)
			format = GL_RED;
		else if (num_components == 3)
			format = GL_RGB;
		else if (num_components == 4)
			format = GL_RGBA;		
 
		glBindTexture(GL_TEXTURE_2D, textureID);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1); // Recommended by NVIDIA Rep: https://devtalk.nvidia.com/default/topic/875205/opengl/how-does-gl_unpack_alignment-work-/
		
		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, image_data);
		glGenerateMipmap(GL_TEXTURE_2D);
 
		// https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glTexParameter.xhtml
		// ----------------------------------------------------------------------------------------------------------------
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT); // GL_REPEAT... GL_MIRRORED_REPEAT... GL_CLAMP_TO_EDGE... GL_CLAMP_TO_BORDER.
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
 
		// float border_colour[] = {0.45, 0.55, 0.95};
		// glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, border_colour); // For above when using: GL_CLAMP_TO_BORDER		
 
		// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // GL_NEAREST... GL_LINEAR... GL_NEAREST_MIPMAP_NEAREST (See above link for full list)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // GL_NEAREST or GL_LINEAR.
 
		stbi_image_free(image_data);
		std::cout << "Image loaded OK\n\n";
	}
	else
	{		
		stbi_image_free(image_data);
		std::cout << "Image failed to load\n\n";
	}	
	return textureID;
}

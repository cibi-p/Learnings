#version 420 core
 
layout (location = 0) in vec3 aPos;	 // Attribute data: vertex(s) X, Y, Z position via VBO set up on the CPU side.
layout (location = 1) in vec2 aTexCoord;
 
flat out vec2 shape_xy_pos_flat; // Vertex position coordinates passed to the fragment shader.
out vec2 shape_xy_pos_varying; // Vertex position coordinates passed as interpolated per-vertex.
out vec2 texture_coordinates;
 
void main()
{
	shape_xy_pos_flat = vec2(aPos.x, aPos.y); // Send values that will not be interpolated in the fragment shader.
	shape_xy_pos_varying = vec2(aPos.x, aPos.y); // These values will be interpolated in the fragment shader.
 
	texture_coordinates = aTexCoord;
		
	// https://www.khronos.org/opengl/wiki/Vertex_Post-Processing
	gl_Position = vec4(aPos, 1.0); // Output to vertex stream for the "Vertex Post-Processing" stage.
}

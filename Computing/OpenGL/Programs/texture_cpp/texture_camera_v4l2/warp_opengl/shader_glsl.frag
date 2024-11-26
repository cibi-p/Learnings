#version 420 core
 
out vec4 fragment_colour;
 
// Must be the exact same name as declared in the vertex shader
// -----------------------------------------------------------------------------------
flat in vec2 shape_xy_pos_flat; // Vertex position coordinates received that are not being interpolated.
in vec2 shape_xy_pos_varying; // Vertex position coordinates received as interpolated per-vertex.
in vec2 texture_coordinates;
 
uniform sampler2D image_1;
uniform sampler2D image_2;
uniform vec2 scroll_texture;
 
mat4 transformation_matrix(vec3 axis, float angle); // Function prototype.
 
void main() // For texture() ... 0,0 = Image bottom left... 1,1 = Top right.
{
	if (abs(shape_xy_pos_flat.y) == 0.75) // Draw triangle
	{
		// Drawing using scrolling X value
		// -----------------------------------------
		fragment_colour = texture(image_2, vec2((texture_coordinates.x + scroll_texture.x), texture_coordinates.y));
 
		// Beetle spots alpha = 0.40 as set in Photoshop
		// ------------------------------------------------------------
		if (fragment_colour.a < 0.40) // Use < 0.40 to execute the else-statement (The background is 100% transparent as set in Photoshop)
			fragment_colour = vec4(0.5, abs(shape_xy_pos_varying.x), abs(shape_xy_pos_varying.y), 0.39); // Set green and blue to varying XY values.
		else	
		{		
			if (fragment_colour.a <  0.41) // Discarding also makes the beetle's spots 100% transparent like when using < 41 above.
				// discard;
				fragment_colour = vec4(0, 0, 1, 0.65); // Manually set the beetle's spot colour.
		}
 
		// Uncommenting the below overrides the above
		// --------------------------------------------------------------
		//		mat4 coords_rot_mat = transformation_matrix(vec3(0.0, 0.0, 1.0), scroll_texture.y * shape_xy_pos_varying.x);  // Use to rotate and stretch the image.
		//		vec2 new_coords = vec2(mat3(coords_rot_mat) * vec3(texture_coordinates, 0.0));
		//
		//		new_coords.y += scroll_texture.y * 1.5;
		//
		//		fragment_colour = texture(image_2, new_coords);
		//
		//		if (fragment_colour.a < 0.41)
		//		{
		//			if (fragment_colour.a != 0)
		//				fragment_colour = vec4(0, abs(new_coords.x * 2), abs(new_coords.y), 0.95); // Manually set the beetle's spot colour.
		//			else
		//				fragment_colour = vec4(0.5, abs(shape_xy_pos_varying.x), abs(shape_xy_pos_varying.y), 0.35);
		//		}
 
		//		if (new_coords.x > 1 || new_coords.x < 0)
		//		{
		//			fragment_colour.r = abs(new_coords.x - floor(new_coords.x));
		//			fragment_colour.g = abs(new_coords.y - floor(new_coords.y));
		//			fragment_colour.b = 1.0;
		//		}
		//
		//		if (new_coords.y > 1 || new_coords.y < 0)
		//		{
		//			fragment_colour.r = abs(new_coords.y - floor(new_coords.y)) * 1.25;
		//			fragment_colour.g = abs(new_coords.x - floor(new_coords.x));
		//			fragment_colour.b = 0.65;
		//		}
		
		// discard; // Used to completely disable drawing the triangle.
	}
	else // Draw rectangle
	{		
		// fragment_colour = vec4(vec3(texture(image_1, vec2(texture_coordinates.x + scroll_texture.x, texture_coordinates.y))), 1.0); // Drawing using scrolling X value.
		// fragment_colour = vec4(vec3(texture(image_1, vec2(texture_coordinates.x, texture_coordinates.y + scroll_texture.y))), 1.0); // Drawing using scrolling Y value.
		// fragment_colour = vec4(vec3(texture(image_1, vec2(texture_coordinates.x + scroll_texture.x, texture_coordinates.y + scroll_texture.y))), 1.0); // Drawing using scrolling X and Y value.
			
		// Uncommenting the below overrides the above
		// --------------------------------------------------------------
		// mat4 coords_rot_mat = transformation_matrix(vec3(0.0, 0.0, 1.0), scroll_texture.x); // Use to only rotate the image.
		mat4 coords_rot_mat = transformation_matrix(vec3(0.0, 0.0, 1.0), scroll_texture.x * shape_xy_pos_varying.y); // Use to rotate and stretch the image.
		
		vec2 new_coords = vec2(mat3(coords_rot_mat) * vec3(texture_coordinates, 0.0));
		
		new_coords.y += scroll_texture.y;
				
		fragment_colour = vec4(vec3(texture(image_1, new_coords)), 1.0);		
 
		// Set border colour for texture coordinates outside [0, 1]
		// ------------------------------------------------------------------------
		// float new_x_coord = texture_coordinates.x + scroll_texture.x; // Produces straight horizontal and vertical borders. 
		// float new_y_coord = texture_coordinates.y + scroll_texture.y;
		
		float new_x_coord = new_coords.x; // Produces curved borders that follow the shape of the distortion.
		float new_y_coord = new_coords.y;
						
		if (new_x_coord > 1 || new_x_coord < 0)
		{
			fragment_colour.r = abs(new_x_coord - floor(new_x_coord));
			fragment_colour.g = abs(new_y_coord - floor(new_y_coord));		
			fragment_colour.b = 0.35;
		}
										
		if (new_y_coord > 1 || new_y_coord < 0)
		{
			fragment_colour.r = abs(new_y_coord - floor(new_y_coord));
			fragment_colour.g = abs(new_x_coord - floor(new_x_coord));			
			fragment_colour.b = 0.55;
		}	
	}
}
 
mat4 transformation_matrix(vec3 axis, float angle) // http://www.opengl-tutorial.org/beginners-tutorials/tutorial-3-matrices/ ... http://www.songho.ca/opengl/gl_anglestoaxes.html
{
    axis = normalize(axis); // Axis to rotate around // DO NOT Normalize (Else it crashes) Zero vectors, i.e., when all three values are: 0... (0, 0, 0)
 
    float s = sin(angle);  // Angle in radians.
    float c = cos(angle); // Cosine of the angle [-1.0, 1.0]
    float oc = 1.0 - c;      // Range [0, 2]
 
    return mat4 
    (			
	 oc * axis.x * axis.x + c,                    oc * axis.x * axis.y - axis.z * s,	 oc * axis.z * axis.x + axis.y * s,      0.0,	
         oc * axis.x * axis.y + axis.z * s,      oc * axis.y * axis.y + c,                      oc * axis.y * axis.z - axis.x * s,       0.0,
         oc * axis.z * axis.x - axis.y * s,       oc * axis.y * axis.z + axis.x * s,        oc * axis.z * axis.z + c,                    0.0,
         0.0,                                                    0.0,                                                       0.0,                                                    1.0
    );
}

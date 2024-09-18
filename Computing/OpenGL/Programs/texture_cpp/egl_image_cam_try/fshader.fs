#version 320 es
precision mediump float;
out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;

// texture sampler
uniform sampler2D texture1;

void main()
{
	vec4 temp = texture(texture1, TexCoord);
	FragColor = temp + 0.0;
}
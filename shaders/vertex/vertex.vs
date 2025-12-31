
#version 410 core
layout (location=0) in vec3 aPos;
layout (location=1) in vec3 aCol;
layout (location=2) in vec2 aTexCoord;

out vec4 vertexColor;
out vec4 newColor;
out vec2 TexCoord;

uniform vec4 offset;
uniform mat4 transform;
uniform mat4 view;
uniform mat4 model;
uniform mat4 projection;


void main()
{
	gl_Position =   projection * view * model * vec4(aPos.x,aPos.y,aPos.z,1.0) ;
	newColor = vec4(aPos,1.0);
	vertexColor = vec4(aCol,1.0);
	TexCoord = vec2(aTexCoord.x,aTexCoord.y);
}
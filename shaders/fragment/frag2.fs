#version 410 core
out vec4 FragColor;
uniform vec4 ourColor;
uniform sampler2D ourTexture;
in vec4 vertexColor;
in vec4 newColor;
in vec2 TexCoord;
void main()
{
 FragColor = texture(ourTexture,TexCoord) * vertexColor  ;
}
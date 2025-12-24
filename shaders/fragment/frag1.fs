#version 410 core
out vec4 FragColor;

uniform float vals;
uniform vec4 ourColor;
uniform sampler2D ourTexture;
uniform sampler2D ourTexture1;

in vec4 vertexColor;
in vec4 newColor;
in vec2 TexCoord;
void main()
{
    FragColor = mix(texture(ourTexture,TexCoord) ,texture(ourTexture1,vec2(-TexCoord.x,TexCoord.y)),vals) * vertexColor  ;
}
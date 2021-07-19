#version 330 core
out vec4 FragColor;

uniform vec3 objectcolor;
uniform vec3 lightcolor;

void main()
{
    FragColor = vec4(objectcolor * lightcolor, 1.0);
}

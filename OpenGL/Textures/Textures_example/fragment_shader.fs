#version 330 core
out vec4 FragColor;

in vec3 ourcolor;
in vec2 textcoord;

uniform sampler2D texture1;
void main()
{
    FragColor = texture(texture1, textcoord);
}

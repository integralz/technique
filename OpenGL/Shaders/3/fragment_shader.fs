#version 330 core
out vec4 FragColor;
in vec4 get_position;
void main()
{
    FragColor = get_position;
}

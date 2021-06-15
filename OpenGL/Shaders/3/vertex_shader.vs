#version 330 core
layout (location = 0) in vec3 aPos;
out vec4 get_position;

void main()
{
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
    get_position = gl_Position;
}
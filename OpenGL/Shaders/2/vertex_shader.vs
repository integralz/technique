#version 330 core
layout (location = 0) in vec3 aPos;
uniform float parallel_movement;

void main()
{
    gl_Position = vec4(aPos.x + parallel_movement, aPos.y, aPos.z, 1.0);
}

#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 atextcoord;

out vec2 textcoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection * view * model * vec4(aPos.x, aPos.y, aPos.z, 1.0f);
    textcoord = vec2(atextcoord.x, 1.0 - atextcoord.y);
}

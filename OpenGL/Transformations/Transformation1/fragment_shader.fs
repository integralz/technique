#version 330 core
out vec4 FragColor;

in vec3 ourcolor;
in vec2 textcoord;

uniform float mixvalue;
uniform sampler2D texture1;
uniform sampler2D texture2;
void main()
{
    FragColor = mix(texture(texture1, textcoord), texture(texture2, textcoord), mixvalue);
}

#version 330 core
out vec4 FragColor;

in vec3 ourcolor;
in vec2 textcoord;

uniform sampler2D texture1;
uniform sampler2D texture2;
void main()
{
    FragColor = mix(texture(texture1, textcoord), texture(texture2, vec2(1.0f, 0.0f) - textcoord), 0.2);
}

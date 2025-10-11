#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aCol;

uniform int offset;

out vec3 ourColor;
out vec3 outPos;

void main() {
  gl_Position = vec4(aPos.x + offset, aPos.y, aPos.z, 1.0);
  ourColor = aCol;
  outPos = aPos;
}

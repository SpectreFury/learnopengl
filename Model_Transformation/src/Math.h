#pragma once

struct vec3 {
  float x;
  float y;
  float z;
};

struct mat4 {
  float entries[16];
};

mat4 create_identity_matrix(); 

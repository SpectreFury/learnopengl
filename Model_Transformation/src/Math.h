#pragma once

struct vec3 {
  float x;
  float y;
  float z;
};

struct mat4 {
  float entries[16];
};

mat4 create_scale_matrix(vec3 scale); 
mat4 create_translation_matrix(vec3 translation); 

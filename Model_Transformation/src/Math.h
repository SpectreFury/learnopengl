#pragma once
#include <cmath>
#define PI 3.14159265

struct vec3 {
  float x;
  float y;
  float z;
};

struct mat4 {
  float entries[16];
};

mat4 create_identity();
mat4 create_scale_matrix(mat4 matrix, vec3 scale); 
mat4 create_translation_matrix(mat4 matrix, vec3 translation); 
mat4 create_z_rotation_matrix(mat4 matrix, float degree);

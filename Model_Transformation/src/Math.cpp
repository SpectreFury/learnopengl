#include "Math.h"

mat4 create_identity() {
  mat4 matrix;

  matrix.entries[0] = 1.0f;
  matrix.entries[1] = 0.0f;
  matrix.entries[2] = 0.0f;
  matrix.entries[3] = 0.0f;

  matrix.entries[4] = 0.0f;
  matrix.entries[5] = 1.0f;
  matrix.entries[6] = 0.0f;
  matrix.entries[7] = 0.0f;

  matrix.entries[8] = 0.0f;
  matrix.entries[9] = 0.0f;
  matrix.entries[10] = 1.0f;
  matrix.entries[11] = 0.0f;

  matrix.entries[12] = 0.0f;
  matrix.entries[13] = 0.0f;
  matrix.entries[14] = 0.0f;
  matrix.entries[15] = 1.0f;

  return matrix;
}

mat4 multiply_mat4(mat4 a, mat4 b) {
  mat4 result = {0};

  for (int col = 0; col < 4; col++) {
    for (int row = 0; row < 4; row++) {
      result.entries[col * 4 + row] =
          a.entries[0 * 4 + row] * b.entries[col * 4 + 0] +
          a.entries[1 * 4 + row] * b.entries[col * 4 + 1] +
          a.entries[2 * 4 + row] * b.entries[col * 4 + 2] +
          a.entries[3 * 4 + row] * b.entries[col * 4 + 3];
    }
  }

  return result;
}

mat4 create_translation_matrix(mat4 matrix, vec3 translation) {
  mat4 trans;

  trans.entries[0] = 1.0f;
  trans.entries[1] = 0.0f;
  trans.entries[2] = 0.0f;
  trans.entries[3] = 0.0f;

  trans.entries[4] = 0.0f;
  trans.entries[5] = 1.0f;
  trans.entries[6] = 0.0f;
  trans.entries[7] = 0.0f;

  trans.entries[8] = 0.0f;
  trans.entries[9] = 0.0f;
  trans.entries[10] = 1.0f;
  trans.entries[11] = 0.0f;

  trans.entries[12] = translation.x;
  trans.entries[13] = translation.y;
  trans.entries[14] = translation.z;
  trans.entries[15] = 1.0f;

  return multiply_mat4(trans, matrix);
}

mat4 create_scale_matrix(mat4 matrix, vec3 scale) {
  mat4 scale_matrix;

  scale_matrix.entries[0] = scale.x;
  scale_matrix.entries[1] = 0.0f;
  scale_matrix.entries[2] = 0.0f;
  scale_matrix.entries[3] = 0.0f;

  scale_matrix.entries[4] = 0.0f;
  scale_matrix.entries[5] = scale.y;
  scale_matrix.entries[6] = 0.0f;
  scale_matrix.entries[7] = 0.0f;

  scale_matrix.entries[8] = 0.0f;
  scale_matrix.entries[9] = 0.0f;
  scale_matrix.entries[10] = scale.z;
  scale_matrix.entries[11] = 0.0f;

  scale_matrix.entries[12] = 0.0f;
  scale_matrix.entries[13] = 0.0f;
  scale_matrix.entries[14] = 0.0f;
  scale_matrix.entries[15] = 1.0f;

  return multiply_mat4(scale_matrix, matrix);
}

mat4 create_z_rotation_matrix(mat4 matrix, float degree) {
  mat4 rotation_matrix;

  float radians = degree * (PI / 180);

  float C = cos(radians);
  float S = sin(radians);
  
  rotation_matrix.entries[0] = C;
  rotation_matrix.entries[1] = S;
  rotation_matrix.entries[2] = 0.0f;
  rotation_matrix.entries[3] = 0.0f;

  rotation_matrix.entries[4] = -S;
  rotation_matrix.entries[5] = C;
  rotation_matrix.entries[6] = 0.0f;
  rotation_matrix.entries[7] = 0.0f;

  rotation_matrix.entries[8] = 0.0f;
  rotation_matrix.entries[9] = 0.0f;
  rotation_matrix.entries[10] = 1.0f;
  rotation_matrix.entries[11] = 0.0f;

  rotation_matrix.entries[12] = 0.0f;
  rotation_matrix.entries[13] = 0.0f;
  rotation_matrix.entries[14] = 0.0f;
  rotation_matrix.entries[15] = 1.0f;

  return multiply_mat4(rotation_matrix, matrix);
}

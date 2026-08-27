#include "Math.h"

mat4 create_identity_matrix() {
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
  matrix.entries[11] = 1.0f;

  matrix.entries[12] = 0.0f;
  matrix.entries[13] = 0.0f;
  matrix.entries[14] = 0.0f;
  matrix.entries[15] = 1.0f;

  return matrix;
}

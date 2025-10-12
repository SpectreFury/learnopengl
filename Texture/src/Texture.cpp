#include "Texture.h"
#include "stb_image.h"

Texture::Texture(const char *texturePath) {
  glGenTextures(1, &ID);
  glBindTexture(GL_TEXTURE_2D, ID);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                  GL_LINEAR_MIPMAP_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_LINEAR);

  stbi_set_flip_vertically_on_load(true);

  int width, height, nrChannels;
  unsigned char *data = stbi_load(texturePath, &width, &height, &nrChannels, 0);

  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
  glGenerateMipmap(GL_TEXTURE_2D);

  stbi_image_free(data);
}

void Texture::use(Shader& shader, const char* uniform, int offset) {
  shader.use();
  shader.setInt(uniform, offset);

  glActiveTexture(GL_TEXTURE0 + offset);
  glBindTexture(GL_TEXTURE_2D, ID);
}

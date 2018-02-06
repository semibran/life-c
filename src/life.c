#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "life.h"

void generate(unsigned char *data, int width, int height) {
  int area = width * height;
  float r = width / 2;
  float m = width / 3;
  for (int i = 0; i < area; i++) {
    int x = i % width;
    int y = (i - x) / width;
    float dx = r - x;
    float dy = r - y;
    float d = sqrt(dx * dx + dy * dy);
    data[i] = rand() / (RAND_MAX + 1.0) > d / m && rand() % 2;
  }
}

void update(unsigned char *data, unsigned char *next, int width, int height) {
  int area = width * height;
  for (int i = 0; i < area; i++) {
    int x = i % width;
    int y = i / width;
    int n = 0;
    for (int dy = -1; dy <= 1; dy++) {
      int ny = y + dy;
      if (ny < 0) {
        ny += height;
      } else if (ny >= height) {
        ny -= height;
      }
      for (int dx = -1; dx <= 1; dx++) {
        int nx = x + dx;
        if (nx < 0) {
          nx += width;
        } else if (nx >= width) {
          nx -= width;
        }
        n += data[ny * width + nx];
      }
    }
    next[i] = n == 3
      ? 1
      : n == 4
        ? data[i]
        : 0;
  }
  memcpy(data, next, area);
}

void render(unsigned char *pixels, unsigned char *data, int width, int height) {
  int area = width * height;
  for (int i = 0; i < area; i++) {
    int value = data[i] == 1 ? 255 : 0;
    int index = i * 4;
    pixels[index + 0] = value;
    pixels[index + 1] = value;
    pixels[index + 2] = value;
    pixels[index + 3] = 255;
  }
}

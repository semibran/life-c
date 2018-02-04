#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "life.h"

void generate(unsigned char data[], int width, int height) {
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

void update(unsigned char copy[], unsigned char data[], int width, int height) {
  int area = width * height;
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      int i = y * width + x;
      int n = 0;
      for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
          if (!dx && !dy) continue;
          int nx = x + dx;
          int ny = y + dy;
          if (nx < 0) {
            nx += width;
          } else if (nx >= width) {
            nx -= width;
          }
          if (ny < 0) {
            ny += height;
          } else if (ny >= height) {
            ny -= height;
          }
          if (data[ny * width + nx]) {
            n++;
          }
        }
      }
      copy[i] = n == 3
             || n == 2 && data[i] == 1;
    }
  }
  memcpy(data, copy, area);
}

void render(unsigned char pixels[], unsigned char data[], int width, int height) {
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

void update(unsigned char copy[], unsigned char data[], int width, int height) {
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      int i = y * width + x;
      int n = 0;
      for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
          if (!dx && !dy) continue;
          int nx = x + dx;
          int ny = y + dy;
          if (nx < 0) nx += width;
          else if (nx >= width) nx -= width;
          if (ny < 0) ny += height;
          else if (ny >= height) ny -= height;
          if (data[ny * width + nx]) {
            n++;
          }
        }
      }
      copy[i] = n == 3
             || n == 2 && data[i] == 1;
    }
  }
  int area = width * height;
  for (int i = 0; i < area; i++) {
    data[i] = copy[i];
  }
}

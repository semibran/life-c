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

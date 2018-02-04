void generate(unsigned char data[], int width, int height) {
  int area = width * height;
  for (int i = 0; i < area; i++) {
    data[i] = rand() % 2;
  }
}

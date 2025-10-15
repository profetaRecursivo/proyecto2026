int piso(int a, int b) {
  int q = a / b;
  int r = a % b;
  if (r != 0 and ((r > 0) != (b > 0)))
    --q;
  return q;
}

int techo(int a, int b) {
  int q = a / b;
  int r = a % b;
  if (r != 0 and ((r > 0) == (b > 0)))
    q++;
  return q;
}
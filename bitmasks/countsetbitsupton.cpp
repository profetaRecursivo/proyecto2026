// calcula el número total de bits encendidos
// en las representaciones binarias de
// todos los números desde 1 hasta n
int countSetBits(int n) {
	int count = 0;
	while (n > 0) {
		int x = std::bit_width(n) - 1;
		count += x << (x - 1);
		n -= 1 << x;
		count += n + 1;
	}
	return count;
}
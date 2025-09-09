bool esdivpor2alak(int n, int k) {
	int pot = 1 << k;
	return (n & (pot - 1)) == 0;
}
bool espot2(unsigned int n) { 
    return n && !(n & (n - 1)); 
}
int popcount(int n) {
	int count = 0;
	while (n) {
		n = n & (n - 1);
		count++;
	}
	return count;
}
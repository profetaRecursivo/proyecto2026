// convertir un numero en binario log n
string tobin(int n) {
	return bitset<32>(n).to_string().substr(bitset<32>(n).to_string().find('1'))
}
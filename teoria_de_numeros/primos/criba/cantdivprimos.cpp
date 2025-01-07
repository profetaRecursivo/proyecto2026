const int N = 3000;
vector<int> divprimos(N + 1, 0);
void sieve() {
    for (int i = 2; i <= N; i++) {
        if (divprimos[i] == 0) { 
            for (int j = i; j <= N; j += i) {
                divprimos[j]++;
            }
        }
    }
}
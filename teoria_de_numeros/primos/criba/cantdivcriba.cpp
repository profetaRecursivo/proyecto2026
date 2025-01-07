const int N = 1;
vector<int> cantdiv(N + 1, 0);
void sieve() {
    for (int i = 1; i <= N; ++i) {
        for (int j = i; j <= N; j += i) {
            cantdiv[j]++;  
        }
    }
}
//O(log x) si ya tenemos el vector spf
vector<int> prime_factors(int x) {
    vector<int> factors;
    while (x > 1) {
        factors.push_back(spf[x]);
        x /= spf[x];
    }
    return factors;
}


vector<int> prime_factors(int n) {
    vector<int> facts;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            facts.push_back(i);
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) facts.push_back(n);
    return facts;
}

int prime_factors(int n, map<int, int>& facts) {
    int ans = 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                facts[i]++;
                ans++;
                n /= i;
            }
        }
    }
    if (n > 1) {
        facts[n]++;
        ans++;
    }
    return ans;
}


vector<int> prime_factors(int n) {
    vector<int> facts;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            facts.push_back(i);
            n /= i;
        }
    }
    if (n > 1) facts.push_back(n);
    return facts;
}
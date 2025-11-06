struct pto {
	int x, y;
};
struct tupla{
    int signo, num, den;
    bool operator < (const tupla& otro)const{
        return tie(signo, num, den) < tie(otro.signo, otro.num, otro.den);
    }
};
constexpr static inline int signo(int x){
    return (x<0)?-1:1;
}
tupla pend(pto a, pto b){   
    tupla res;
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    int s = signo(dx) * signo(dy);
    if(dx == 0){
        res = {-10, -10, -10};
        return res;
    }else if(dy == 0){
        res = {-20, -20, -20};
        return res;
    }
    dx = abs(dx);
    dy = abs(dy);
    int g = gcd(dx, dy);
    dx/=g;
    dy/=g;
    res = {s, dx, dy};
    return res;
}
void solve(int n) {
	vector<pto> puntos(n);
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		puntos[i] = {a, b};
	}
    int ans = 0;
    for(int i = 0; i<n; i++){
        //fijamos el punto i
        pto ancla = puntos[i];
        map<tupla, int> frec;
        for(int j = 0; j<n; j++){
            if(i ==j)continue;
            frec[pend(ancla, puntos[j])]++;
        }
        int maxi = 0;
        for(auto [pppp, cant]:frec)maxi = max(maxi, cant);
        ans = max(ans, maxi+1);
    }
    cout<<ans<<'\n';
}
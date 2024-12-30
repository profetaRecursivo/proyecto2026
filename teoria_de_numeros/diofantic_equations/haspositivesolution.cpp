int extgcd(int a, int b, int& x, int& y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

void solve(){
    int a, b, c;cin>>a>>b>>c;
    int gcd, x0, y0;
    gcd = extgcd(a, b, x0, y0);
    if (c % gcd != 0) {
        cout<<"No\n";
        return;
    }
    int esc = c / gcd;
    x0 *= esc;
    y0 *= esc;
    int na = a / gcd;
    int nb = b / gcd;
    int mini = ceil(-1.0 * x0 / nb);
    int maxi = floor(1.0 * y0 / na);
    cout<<(mini<=maxi?"Yes\n":"No\n");
}
ll B;
ll BINV;
const ll MOD = 2305843009213693951LL;
inline ll mulmod(ll a, ll b){
    return (ll)((__int128_t)a*b%MOD);
}
struct Hash{
    ll h, b, bi;
    Hash(ll _h = 0, ll _b = 1, ll _bi =1):h(_h), b(_b), bi(_bi){}
    Hash operator*(const Hash& otro)const{
        return Hash((h + mulmod(b, otro.h))%MOD, mulmod(b, otro.b), mulmod(bi, otro.bi));
    }
    bool operator==(const Hash& otro)const{
        return h == otro.h and b == otro.b and bi == otro.bi;
    }
    Hash operator/(const Hash&otro)const{
        return Hash(mulmod(((h - otro.h + 2*MOD)%MOD),otro.bi), mulmod(b, otro.bi), mulmod(bi, otro.b));
    }
    Hash operator+(char c)const{
        return Hash((h + mulmod(b, (c-'0'+1+MOD)%MOD))%MOD, mulmod(b, B), mulmod(bi, BINV));
    }
    Hash operator<<(ll k)const{
        Hash ans;
        Hash x = *this;
        while(k){
            if(k & 1) ans = ans * x;
            x = x * x;
            k >>= 1;
        }
        return ans;
    }

};

void inicializar_hash(){
    mt19937_64 generador(chrono::steady_clock::now().time_since_epoch().count());
    B = 257 + (generador() % (MOD - 300));
    BINV = expmod(B, MOD - 2, MOD);
}

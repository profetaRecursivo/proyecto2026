#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N = 100005;

vector<bool> espri(N+1, true);
void sieve(){
    espri[0] = espri[1] = false;
    for (int i = 2; i * i < N; i++) {
        if (espri[i]) {
            for (int j = i * i; j <N; j += i)
                espri[j] = false;
        }
    }
}


signed main(){
    sieve();
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    if(n==1){
        cout<<"1\n1\n";
        return 0;
    }else if(n == 2){
        cout<<"1\n1 1\n";
        return 0;
    }
    cout<<"2\n";
    for(int i = 2; i<=n+1; i++){
        if(espri[i])cout<<1<<' ';else cout<<2<<' ';
    }
    cout<<'\n';
}

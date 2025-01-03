#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e18;
const int N = 1010;
vector<bool> is_prime(N+1, true);
vector<int> primos;
void sieve(){
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= N; i++) {
        if(is_prime[i])primos.push_back(i);
        if (is_prime[i] && (ll)i * i <= N) {            
            for (int j = i * i; j <= N; j += i)
                is_prime[j] = false;
        }
    }
}
bitset<N> arr;
int ans[N];
void pre(){
    sieve();
    for(int i = 1; i<(int)(primos.size()); i++){
        int num = primos[i] + primos[i-1];
        if(num + 1>= N)break;
        arr[num+1] = is_prime[num+1];
        //cout<<num+1<<' '; 
    }
    ans[0] = arr[0];
    for(int i = 1;i<N; i++){
        ans[i] = arr[i] + ans[i-1];
    }
}
void solve(){
    int n, k;cin>>n>>k;
    cout<<(ans[n]>=k?"YES":"NO")<<endl;
}
signed main(){
    pre();
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    //cin>>t;
    while(t--)solve();
}
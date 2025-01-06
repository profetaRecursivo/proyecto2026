#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N  = 10000050;
vector<int> spf(N + 1);
vector<int> prim;

void sieve()
{
    for (int i = 2; i <= N; ++i)
    {
        if (spf[i] == 0)
        {
            spf[i] = i;
            prim.push_back(i);
        }
        for (int j = 0; i * prim[j] <= N; ++j)
        {
            spf[i * prim[j]] = prim[j];
            if (prim[j] == spf[i])
            {
                break;
            }
        }
    }
}
vector<int> cuarta;
vector<int> sq;
const int tam = 10000000;
vector<int> chamo;
void init(){
    sieve();
    set<int> st;
    int i = 1;
    while(i*i*i*i <= tam){
        cuarta.push_back(i*i*i*i);
        i++;
    }
    i = 1;
    while(i*i <= tam){
        sq.push_back(i*i);
        i++;
    }
    //cout<<sq.size()<<' '<<cuarta.size()<<endl;;
    const int cuarlen = (int)cuarta.size();
    const int sqlen = (int)sq.size();
    for(i = 0; i<cuarlen; i++){
        for(int j = 0; j<sqlen; j++){
            int num = cuarta[i] + sq[j];
            if(num > N){
                break;
            } 
            if(spf[num] == num){
                st.insert(num);
            }
        }
    }
    //cout<<st.size()<<endl;
    for(const int& i:st)chamo.push_back(i);
}
void solve(){
    int x;cin>>x;
    int l = 0, r = (int)chamo.size() -1;
    int ans;
    bool ok = 0;
    while(l<=r){
        int mid = (l+r)/2;
        if(chamo[mid] == x){
            ans = mid;
            ok = 1;
            break;
        }else if(chamo[mid] < x){
            ans = mid;
            ok = 1;
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    if(ok){
        cout<<ans+1<<endl;
    }else{
        cout<<0<<endl;
    }
}
signed main(){
    init();
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    cin>>t;while(t--)solve();
}
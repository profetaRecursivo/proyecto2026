#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define fore(i, a, b) for(int i = (a); i<(b); i++)
#define FOR(i, n) for(int i = 0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using vi = vector<int>;
const int MOD = 1000000007;
const ll INF = 9223372036854775807LL;
map<char, int> maxi;
map<char, int> mini;
char findmax(vector<char> vec){
    char x = '$';
    for(int i = 0; i<sz(vec); i++){
        x = max(x, vec[i]);
    }
    return x;
}
char findmin(vector<char> vec){
    char x = 'z';
    for(int i = 0; i<sz(vec); i++){
        x = min(x, vec[i]);
    }
    return x;
}
void solve(int i, vector<char> arr, vector<char> actual){
    if(i == sz(arr)){
        maxi[findmax(actual)]++;
        mini[findmin(actual)]++;
    }else{
        actual.push_back(arr[i]);
        solve(i+1, arr, actual);
        actual.pop_back();
        solve(i+1, arr, actual);
    }
}
void solve(){
    int n = 4;
    vector<char> arr = {'a', 'b', 'c', 'd'};
    solve(0, arr, vector<char>(0));
    for(auto[x, y]:maxi){
        cout<<x<<' '<<y<<endl;
    }
    cout<<"------\n";
    for(auto[x, y]:mini){
        cout<<x<<' '<<y<<endl;
    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
}
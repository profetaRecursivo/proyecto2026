#include <bits/stdc++.h>
using namespace std;
#define ll long long
signed main(){
    ll ans = 0;
    int n;cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr, arr + n);
    for(int i = 0; i<n; i++){
        ans+=(arr[i]*(1<<(i))-1);
    }
    for(int i = 0; i<n; i++){
        ans-=(arr[i]*(1<<(n-i-1))-1);
    }
    cout<<ans<<endl;
}
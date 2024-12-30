#include <bits/stdc++.h>
using namespace std;

signed main(){
    int t;
    scanf("%d", &t);
    while(t--){
        long long a, b;
        scanf("%lld %lld", &a, &b);
        if(__gcd(a, b)> 1){
            printf("-1\n");
        }else{
            long long ans = (a * b) - a - b + 1;
            printf("%lld\n",ans);
        } 
    }
}

// You are given an array a1,a2,…,an
//  of integer numbers.

// Your task is to divide the array into the maximum number of segments in such a way that:

// each element is contained in exactly one segment;
// each segment contains at least one element;
// there doesn't exist a non-empty subset of segments such that bitwise XOR of the numbers from them is equal to 0
// .
// Print the maximum number of segments the array can be divided into. Print -1 if no suitable division exists.
const int tam =31;
int basis[tam] =  {0};
bool insert(int x){
    for(int  i  = tam-1; i>=0; i--){
        if(x&(1<<i)){
            if(!basis[i]){
                basis[i] = x;
                return  1;
            }
            x^=basis[i];
        }
    }
    return 0;
}
void solve(){
    int n;cin>>n; 
    int tot = 0;
    int ans = 0;
    for(int  i = 0; i<n; i++){
        int x;cin>>x;
        tot^=x;
        ans+=insert(x);
    }
    cout<<(tot?ans:-1)<<'\n';
}
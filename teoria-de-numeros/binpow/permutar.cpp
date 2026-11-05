Permu operator*(const Permu& otro){
        vector<int> nuevo(sz(p));
        int n = sz(p);
        for(int i = 0; i<n; i++){
            nuevo[i] = p[otro.p[i]];
        }   
        return Permu(nuevo);
}

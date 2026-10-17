struct Node{
    int mask;
    Node(char letra){
        int pos = letra-'a';mask = (1<<pos);
    }
};
Node merge(const Node& a, const Node&b){
    Node ans;
    ans.mask = a.mask | b.mask;
    return ans;
}
vector<int> lazy[4*tam];
bool haslazy[4*tam];
Node tr[4*tam];

void push(int node, int b, int e) {
    if (!haslazy[node]) return;
    if(b!=e){
        int mid = (b + e) / 2;
        int l = node * 2;
        int r = l + 1;
        haslazy[l] = true;
        int maskl = 0;
        for (int i = 0; i < 26; i++) {
            lazy[l][i] = lazy[node][lazy[l][i]];
            if ((tr[l].mask >> i) & 1) {
                maskl |= (1 << lazy[l][i]);
            }
        }
        tr[l].mask = maskl;
        haslazy[r] = true;
        int maskr = 0;
        for (int i = 0; i < 26; i++) {
            lazy[r][i] = lazy[node][lazy[r][i]];
            if ((tr[r].mask >> i) & 1) {
                maskr |= (1 << lazy[r][i]);
            }
        }
        tr[r].mask = maskr;
        haslazy[node] = false;
        iota(all(lazy[node]), 0);
    }
    
}

void update(int node, int b, int e, int i, int j, int viejo, int nuevo){
    push(node, b, e);
    if(!(tr[node].mask>>viejo&1))return;
    if(i<=b and e<=j){
        if(tr[node].mask>>viejo&1){
            //si esta
            haslazy[node]=1;
            for(int i = 0; i<26; i++){
                if(lazy[node][i] == viejo)lazy[node][i] = nuevo;
            }
            tr[node].mask^=(1<<viejo);
            tr[node].mask|=(1<<nuevo);
        }
        push(node, b, e);
        return;
    }

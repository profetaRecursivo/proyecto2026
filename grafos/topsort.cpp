//definir  el n
vector<int> topo(vector<vector<int>>& g, vector<int>&in){
    vector<int> ans;
    queue<int> pend;
    for(int i = 1; i<=n; i++){
        if(!in[i])pend.push(i);       
    }
    while(!pend.empty()){
        int actual = pend.front();pend.pop();
        ans.push_back(actual);
        for(int& vecino:g[actual]){
            in[vecino]--;
            if(in[vecino] == 0)pend.push(vecino);
        }
    }
    return ans;
}
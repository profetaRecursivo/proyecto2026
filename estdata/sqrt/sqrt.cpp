struct Nodo {
    int v;
    Nodo(int x = 0) : v(x) {}
    Nodo& operator+=(const Nodo& o){
        v += o.v;
        return *this;
    }
};


struct Sqrt {
    int n, raiz;
    vector<Nodo> a;
    vector<Nodo> blocks;

    Sqrt(const vector<Nodo>& arr){
        a = arr;
        n = a.size();
        raiz = sqrt(n) + 1;
        blocks.assign( (n + raiz - 1) / raiz , Nodo() );
        build();
    }

    void build(){
        for(int i = 0; i < n; i++){
            blocks[i / raiz] += a[i];
        }
    }

    void update(int pos, const Nodo& val){
        int b = pos / raiz;
        a[pos] = val;

        Nodo acum = Nodo();
        int ini = b * raiz;
        int fin = min(n, ini + raiz);

        for(int i = ini; i < fin; i++)
            acum += a[i];

        blocks[b] = acum;
    }

    Nodo query(int l, int r){
        Nodo ans = Nodo();

        while(l <= r){
            int b = l / raiz;
            int ini = b * raiz;
            int fin = min(n, ini + raiz) - 1;

            if(l == ini and fin <= r){
                ans += blocks[b];
                l = fin + 1;
            } else {
                ans += a[l];
                l++;
            }
        }

        return ans;
    }
};
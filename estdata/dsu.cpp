struct unionFind {
    vi p;
    vi size;
    int components;
	//inicializar extra
    unionFind(int n) : p(n, -1), size(n, 1), components(n) {}
    int findParent(int v) {
        if (p[v] == -1) return v;
        return p[v] = findParent(p[v]);
    }
    bool join(int a, int b) {
        a = findParent(a);
        b = findParent(b);
        if (a == b) return false;
        if (size[a] < size[b])
            swap(a, b);
        p[b] = a;
        size[a] += size[b];
        components--;
		//extra[a] = f(extra[b]); -> extra[findparent(x)];
        return true;
    }
};
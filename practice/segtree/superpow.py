# // superpower(l, r) = pow(pow(... pow(pow(al, a(l + 1)), a(l + 2)) ... a(r - 1)), ar).
# // segment tree de potencias, modulo M no necesariamente primo.
import sys
def phi(x: int) -> int:
    if x == 1:
        return 1
    res = x
    t = x
    p = 2
    while p * p <= t:
        if t % p == 0:
            while t % p == 0:
                t //= p
            res = res // p * (p - 1)
        p += 1 if p == 2 else 2
    if t > 1:
        res = res // t * (t - 1)
    return res

class ProdNode:
    __slots__ = ('mod', 'cap')
    def __init__(self, mod=1, cap=1):
        self.mod = mod
        self.cap = cap

def merge_prod(a: ProdNode, b: ProdNode, phi_m: int) -> ProdNode:
    res = ProdNode()
    res.mod = (a.mod * b.mod) % phi_m
    prod_cap = a.cap * b.cap
    res.cap = prod_cap if prod_cap < phi_m else phi_m
    return res

class ProdSegTree:
    def __init__(self, arr, phi_m):
        self.n = len(arr)
        self.phi = phi_m
        self.size = 1
        while self.size < self.n:
            self.size <<= 1
        self.st = [ProdNode(1,1) for _ in range(2*self.size)]
        for i in range(self.n):
            v = arr[i] % self.phi
            cap = arr[i] if arr[i] < self.phi else self.phi
            self.st[self.size + i] = ProdNode(v, cap)
        for i in range(self.size - 1, 0, -1):
            self.st[i] = merge_prod(self.st[i<<1], self.st[i<<1|1], self.phi)

    def update(self, pos, val):
        p = self.size + pos
        self.st[p] = ProdNode(val % self.phi, val if val < self.phi else self.phi)
        p >>= 1
        while p:
            self.st[p] = merge_prod(self.st[p<<1], self.st[p<<1|1], self.phi)
            p >>= 1

    def query(self, l, r):
        # returns ProdNode for product of arr[l..r]
        l += self.size; r += self.size
        left = ProdNode(1,1); right = ProdNode(1,1)
        while l <= r:
            if (l & 1) == 1:
                left = merge_prod(left, self.st[l], self.phi)
                l += 1
            if (r & 1) == 0:
                right = merge_prod(self.st[r], right, self.phi)
                r -= 1
            l >>= 1; r >>= 1
        return merge_prod(left, right, self.phi)

def main():
    data = sys.stdin.buffer.read().split()
    it = iter(data)
    n = int(next(it)); q = int(next(it)); m = int(next(it))
    a = [int(next(it)) for _ in range(n)]

    phi_m = phi(m)
    st = ProdSegTree(a, phi_m)

    out_lines = []
    for _ in range(q):
        typ = next(it).decode()   # 'u' or 'q' (sample uses 0-based indices)
        if typ == 'u':
            k = int(next(it))     # 0-based in problem sample
            v = int(next(it))
            a[k] = v
            st.update(k, v)
        else:  # 'q'
            l = int(next(it))     # 0-based in sample
            r = int(next(it))
            if l == r:
                out_lines.append(str(a[l] % m))
            else:
                prod_node = st.query(l+1, r)
                exp_mod = prod_node.mod
                exp_big = (prod_node.cap >= phi_m)
                exp = exp_mod + (phi_m if exp_big else 0)
                out_lines.append(str(pow(a[l], exp, m)))

    sys.stdout.write("\n".join(out_lines))

if __name__ == "__main__":
    main()

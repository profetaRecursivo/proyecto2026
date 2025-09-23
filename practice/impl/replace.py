import sys
input = sys.stdin.readline
mod = 10**9+7

def solve():
    n = int(input())
    tokens = input().strip().split()

    stack = []  # guarda tuplas (prev_acc, depth_at_prev_acc)
    depth = 0
    cur = None  # acumulador del nivel actual (None = no elemento aún)
    #100 100 = 100 + 100
    def combine(a, b, depth):
        if a is None:
            return b % mod
        if depth % 2 == 0:
            return (a + b) % mod
        else:
            return (a * b) % mod

    for tok in tokens:
        if tok == '(':
            stack.append((cur, depth))
            depth += 1
            cur = None
        elif tok == ')':
            depth -= 1
            prev_acc, prev_depth = stack.pop()
            cur = combine(prev_acc, cur, prev_depth)
        else:
            val = int(tok) % mod
            cur = combine(cur, val, depth)

    print(int(cur) % mod)

if __name__ == "__main__":
    solve()

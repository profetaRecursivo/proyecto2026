import sys
from collections import defaultdict
input = sys.stdin.readline
fun = int(input())
funciones = defaultdict(list)
for _ in range(fun):
    s = input().replace(",", " ").replace(")", " ").replace("(", " ").strip().split()
    temp = len(s)
    funciones[s[1]].append(s[2:])
v = int(input())
variables =  dict()
for _ in range(v):
    s = input().split()
    variables[s[1]] = s[0]
q = int(input())
for _ in range(q):
    s = input().replace(",", " ").replace(")", " ").replace("(", " ").strip().split()
    parametros = s[1:]
    ans =  0
    for f in funciones[s[0]]:
        ok = True
        if len(f) == len(s)-1:
            for idx in  range(len(f)):
                if not (variables[parametros[idx]] == f[idx] or f[idx] ==  "T"):
                    ok = False
                    break
        else:
            ok =  False
        if ok:
            ans+=1
    print(ans)
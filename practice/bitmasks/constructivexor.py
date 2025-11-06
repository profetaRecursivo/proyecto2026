# // dado n y x, imprimir una secuencia de n numeros distintos no negativos tal que su xor sea x
n, x = map(int, input().split())
if n == 2 and x == 0:
    print("NO")
    exit()
if n == 1:
    print("YES")
    print(x)
    exit()
if n == 2:
    print("YES")
    print(f"0 {x}")
    exit()
xor = 0
print("YES")
for i in range(n-3):
    xor^=(i+1)
    print(i+1, end=" ")

num = 1<<17
otro = 1<<18
ter = (1<<18) + (1<<17)
if xor == x:
    print(f"{num} {otro} {ter}")
else:
    baboso = num^x^xor
    print(f"0 {num} {baboso}")
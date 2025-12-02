def criba_divisores():
    divs = [[] for _ in range(tam + 1)]
    for i in range(1, tam + 1):
        for j in range(i, tam + 1, i):
            divs[j].append(i)
    return divs
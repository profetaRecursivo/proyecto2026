from functools import cmp_to_key

def miComparador(a, b):
    # Ejemplo: primero la más corta, si empatan lexicográfico
    if len(a) != len(b):
        return len(a) - len(b)
    return (a > b) - (a < b)  # equivalente a strcmp
    # Nota: (a>b) es True/False → 1/0, igual para (a<b)

arr = ["bbb", "a", "cc", "ab"]
arr.sort(key=cmp_to_key(miComparador))
print(arr)

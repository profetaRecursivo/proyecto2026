"""Módulo functools_demo.py: Uso de functools en Python (permitido en concursos)"""
from functools import lru_cache

@lru_cache(maxsize=None)
def fib(n):
    if n < 2:
        return n
    return fib(n-1) + fib(n-2)

def main():
    print("Fibonacci cache demo:")
    for i in range(10):
        print(fib(i), end=' ')
    print()

if __name__ == "__main__":
    main()

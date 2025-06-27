# counter_demo.py
"""Uso de Counter: cuenta ocurrencias de elementos (como multiset)"""

from collections import Counter

def main():
    a = [1, 2, 2, 3, 3, 3]
    c = Counter(a)
    print("Conteo:", c)
    print("Frecuencia de 2:", c[2])
    print("Elementos únicos:", list(c.keys()))

if __name__ == "__main__":
    main()

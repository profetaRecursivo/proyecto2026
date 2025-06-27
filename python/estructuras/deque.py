# deque_demo.py
"""Uso de deque: cola doble"""

from collections import deque

def main():
    d = deque()
    d.append(1)             # Añade al final
    d.appendleft(2)         # Añade al inicio
    print("Deque:", list(d))
    d.pop()                 # Quita del final
    d.popleft()             # Quita del inicio
    print("Después de quitar:", list(d))

if __name__ == "__main__":
    main()

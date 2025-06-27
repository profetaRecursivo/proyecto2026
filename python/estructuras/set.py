# set_demo.py
"""Uso básico de sets (conjuntos sin elementos repetidos)"""

def main():
    s = set()
    s.add(3)
    s.add(5)
    s.add(3)               # No se agrega repetido
    print("Set contiene:", s)
    print("¿5 está en el set?", 5 in s)
    s.remove(3)            # Elimina el elemento 3

if __name__ == "__main__":
    main()

"""Módulo 2: Listas y Operaciones con Strings en Python"""
def demo_lists_strings():
    # Crear una lista de tamaño n inicializada con ceros
    n = 5
    a = [0] * n
    print("Lista de ceros:", a)

    # Lectura de string y operaciones de slicing
    s = "programacion"
    print("Cadena original:", s)

    # Invertir cadena
    rev = s[::-1]
    print("Cadena invertida:", rev)

    # Subcadena de índices 2 a 5 (excluye 5)
    sub = s[2:5]
    print("Subcadena índices [2:5]:", sub)

if __name__ == "__main__":
    demo_lists_strings()

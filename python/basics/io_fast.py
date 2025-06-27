"""Módulo 1: Entrada/Salida Rápida en Python"""
import sys

def read_line():
    """Lee una línea completa desde stdin y quita el salto de línea final."""
    return sys.stdin.readline().rstrip()

def read_ints():
    """Lee una línea de números separados por espacios y devuelve una lista de enteros."""
    return list(map(int, read_line().split()))

def main():
    # Ejemplo de uso:
    print("Introduce una línea de texto:")
    texto = read_line()
    print("Texto leído:", texto)

    print("Introduce una línea de números separados por espacios:")
    nums = read_ints()
    print("Números leídos:", nums)

if __name__ == "__main__":
    main()

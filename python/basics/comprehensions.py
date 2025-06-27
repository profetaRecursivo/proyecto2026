"""Módulo 3: List Comprehensions en Python"""
def demo_comprehensions():
    # Cuadrados de números pares entre 0 y 9
    evens = [i * i for i in range(10) if i % 2 == 0]
    print("Cuadrados de pares 0-9:", evens)

    # Crear lista de pares (i, i^2)
    pairs = [(i, i*i) for i in range(5)]
    print("Pares (i, i^2):", pairs)

if __name__ == "__main__":
    demo_comprehensions()

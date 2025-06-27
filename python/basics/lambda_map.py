"""Módulo 4: Funciones Lambda y map() en Python"""
def demo_lambda_map():
    # Función anónima que eleva al cuadrado
    sq = lambda x: x * x
    nums = [0, 1, 2, 3, 4]
    squares = list(map(sq, nums))
    print("Cuadrados con map y lambda:", squares)

    # Parsing rápido de cadenas a enteros
    data = "10 20 30 40"
    nums2 = list(map(int, data.split()))
    print("Enteros parseados:", nums2)

if __name__ == "__main__":
    demo_lambda_map()

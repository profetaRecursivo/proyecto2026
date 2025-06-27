"""Módulo 5: enumerate() y reversed() en Python"""
def demo_enum_reversed():
    nums = [10, 20, 30, 40]
    
    # enumerate: índice y valor
    print("Usando enumerate():")
    for i, x in enumerate(nums):
        print(f"Índice {i}, Valor {x}")

    # reversed: recorrer en orden inverso
    print("\nUsando reversed():")
    for x in reversed(nums):
        print(x)

if __name__ == "__main__":
    demo_enum_reversed()

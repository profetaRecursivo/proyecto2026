# dict_demo.py
"""Uso de diccionarios como hash maps (clave: valor)"""

def main():
    m = {}                    # diccionario vacío
    m["hola"] = 5
    m["adiós"] = 10
    print("Valor asociado a 'hola':", m["hola"])
    print("Todas las claves:", list(m.keys()))

    # Recorrer clave y valor
    for clave, valor in m.items():
        print(f"{clave} -> {valor}")

if __name__ == "__main__":
    main()

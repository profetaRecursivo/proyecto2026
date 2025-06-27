# list_demo.py
"""Uso básico de listas (equivalente a vector en C++)"""

def main():
    a = [1, 2, 3]          # Lista con elementos
    a.append(4)            # Agrega al final
    a.pop()                # Elimina el último
    a.insert(1, 10)        # Inserta 10 en la posición 1
    print("Lista final:", a)

if __name__ == "__main__":
    main()
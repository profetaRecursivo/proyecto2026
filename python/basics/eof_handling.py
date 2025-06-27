"""Módulo 6: Manejo de EOF y múltiples casos en Python"""
import sys

def process_line(line):
    """Ejemplo de procesamiento de línea"""
    print("Procesando:", line.strip())

def main():
    # Lee hasta fin de archivo
    while True:
        try:
            line = sys.stdin.readline()
            if not line:
                break  # fin de archivo
            process_line(line)
        except EOFError:
            break

if __name__ == "__main__":
    main()

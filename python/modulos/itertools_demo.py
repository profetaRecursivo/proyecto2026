"""Módulo itertools_demo.py: Uso de itertools en Python (permitido en concursos)"""
import itertools

def main():
    # product
    print("product([1,2], repeat=2):", list(itertools.product([1,2], repeat=2)))
    # permutations
    print("permutations([1,2,3], 2):", list(itertools.permutations([1,2,3], 2)))
    # combinations
    print("combinations([1,2,3], 2):", list(itertools.combinations([1,2,3], 2)))
    # accumulate
    print("accumulate([1,2,3,4]):", list(itertools.accumulate([1,2,3,4])))

if __name__ == "__main__":
    main()

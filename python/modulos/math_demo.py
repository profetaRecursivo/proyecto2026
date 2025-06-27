"""Módulo math_demo.py: Uso de math en Python (permitido en concursos)"""
import math

def main():
    a, b = 48, 180
    print("gcd(48, 180) =", math.gcd(a, b))
    print("lcm(48, 180) =", math.lcm(a, b))
    n = 17
    print("isqrt(17) =", math.isqrt(n))
    print("factorial(5) =", math.factorial(5))
    print("pow(2, 10) =", math.pow(2, 10))
    print("sqrt(2) =", math.sqrt(2))

if __name__ == "__main__":
    main()

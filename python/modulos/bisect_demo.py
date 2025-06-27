"""Módulo bisect_demo.py: Uso de bisect en Python (permitido en concursos)"""
import bisect

def main():
    a = [1, 3, 3, 7]
    x = 3
    print("bisect_left for 3:", bisect.bisect_left(a, x))
    print("bisect_right for 3:", bisect.bisect_right(a, x))
    # insort to insert while keeping sorted
    bisect.insort(a, 5)
    print("After insort 5:", a)
    # remove element using bisect
    pos = bisect.bisect_left(a, 3)
    if pos < len(a) and a[pos] == 3:
        a.pop(pos)
    print("After removing one 3:", a)

if __name__ == "__main__":
    main()

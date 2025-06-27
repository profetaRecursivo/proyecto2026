"""Módulo collections_demo.py: Uso de collections en Python (permitido en concursos)"""
from collections import deque, defaultdict, Counter

def main():
    # deque
    d = deque([1,2,3])
    d.appendleft(0)
    d.append(4)
    print("deque:", list(d))
    
    # defaultdict
    dd = defaultdict(int)
    for ch in "abbccc":
        dd[ch] += 1
    print("defaultdict counts:", dict(dd))
    
    # Counter
    c = Counter([1,2,2,3,3,3])
    print("Counter:", c)
    print("Most common:", c.most_common(2))

if __name__ == "__main__":
    main()

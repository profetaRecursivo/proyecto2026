# heapq_demo.py
"""Cola de prioridad mínima con heapq"""

import heapq

def main():
    heap = []
    heapq.heappush(heap, 5)
    heapq.heappush(heap, 2)
    heapq.heappush(heap, 9)
    print("Elemento mínimo:", heapq.heappop(heap))  # Siempre da el menor

    # Max-heap simulado (con negativos)
    maxheap = []
    for x in [5, 2, 9]:
        heapq.heappush(maxheap, -x)
    print("Máximo simulando max-heap:", -heapq.heappop(maxheap))

if __name__ == "__main__":
    main()

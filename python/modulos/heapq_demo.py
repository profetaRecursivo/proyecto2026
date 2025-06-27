import heapq

def main():
    heap = []
    for val in [5, 1, 3, 2]:
        heapq.heappush(heap, val)
    print("Min-heap elements popped in order:")
    while heap:
        print(heapq.heappop(heap), end=' ')
    print()
    
    # Simular max-heap
    maxheap = []
    for val in [5, 1, 3, 2]:
        heapq.heappush(maxheap, -val)
    print("Max-heap simulation popped in order:")
    while maxheap:
        print(-heapq.heappop(maxheap), end=' ')
    print()

if __name__ == "__main__":
    main()

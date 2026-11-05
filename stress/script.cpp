#!/bin/bash
# Compilar las tres partes
g++ -O3 -std=c++17 solution.cpp -o solution
g++ -O3 -std=c++17 brute.cpp -o brute
g++ -O3 -std=c++17 gen.cpp -o gen

for ((i = 1; ; ++i)); do
    ./gen $i > input.in
    ./solution < input.in > out_sol.out
    ./brute < input.in > out_brute.out

    if ! diff -w out_sol.out out_brute.out > /dev/null; then
        echo "¡WA encontrado en el test $i!"
        echo "=== INPUT ==="
        cat input.in
        echo "=== TU SALIDA ==="
        cat out_sol.out
        echo "=== SALIDA CORRECTA ==="
        cat out_brute.out
        break
    fi
    echo "Test $i: OK"
done

void gen_tree(int n) {
    cout << n << "\n";
    for (int i = 2; i <= n; i++) {
        int u = i;
        int v = rand_num(1, i - 1);
        cout << u << " " << v << "\n";
    }
}
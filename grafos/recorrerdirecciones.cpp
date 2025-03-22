int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

fore(i, 0, 4) {  // Intentamos las 4 direcciones
    int nx = x + dx[i]; // Nueva fila
    int ny = y + dy[i]; // Nueva columna

    if (nx >= 0 && nx < n && ny >= 0 && ny < m) { // Verificamos límites
        if (!visited[nx][ny]) { // Si no ha sido visitado
            dfs(nx, ny);
        }
    }
}
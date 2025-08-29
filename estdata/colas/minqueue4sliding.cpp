deque<pair<int, int>> q;
int insertados = 0;
int eliminados = 0;

//si queremos el maximo cambiamos la condicion del > por <
void push(int x) {
	while (!q.empty() and q.back().first > x) q.pop_back();
	q.push_back({x, insertados});
	insertados++;
}
void pop() {
	if (!q.empty() and q.front().second == eliminados) q.pop_front();
	eliminados++;
}
int min_top(){
    return q.front().first;
}
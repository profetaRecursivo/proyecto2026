struct stackm {
	stack<pair<int, int>> st;

	stackm() {}

	void push(int new_elem) {
		int new_min = st.empty() ? new_elem : f(new_elem, st.top().second);
		st.push({new_elem, new_min});
	}
	int f(int x, int y) {
		// unico a modificar
		return min(x, y);
	}
	int pop() {
		if (empty()) return -1;
		int removed_element = st.top().first;
		st.pop();
		return removed_element;
	}

	int required() {
		int req = st.top().second;
		return req;
	}
	int top() { return st.empty() ? -1 : st.top().first; }

	bool empty() { return st.empty(); }
};
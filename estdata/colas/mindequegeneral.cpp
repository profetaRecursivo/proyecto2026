struct ordqueue {
    stack<pair<int,int>> s1, s2;

    void push(int x) {
        int mini = s1.empty() ? x : min(x, s1.top().second);
        s1.push({x, mini});
    }

    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                int val = s1.top().first;
                s1.pop();
                int mini = s2.empty() ? val : min(val, s2.top().second);
                s2.push({val, mini});
            }
        }
        int eliminado = s2.top().first;
        s2.pop();
        return eliminado;
    }

    int front() {
        if (s2.empty()) {
            while (!s1.empty()) {
                int val = s1.top().first;
                s1.pop();
                int mini = s2.empty() ? val : min(val, s2.top().second);
                s2.push({val, mini});
            }
        }
        return s2.top().first;
    }

    int getMin() const {
        // precondición: !empty()
        if (s1.empty()) return s2.top().second;
        if (s2.empty()) return s1.top().second;
        return min(s1.top().second, s2.top().second);
    }
};

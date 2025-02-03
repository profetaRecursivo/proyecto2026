#include <deque>
#include <iostream>

class MinQueue {
   private:
	deque<int> dq;
	deque<int> queue;

   public:
	void enqueue(int val) {
		while (!dq.empty() && dq.back() > val) { dq.pop_back(); }
		dq.push_back(val);
		queue.push_back(val);
	}

	void dequeue() {
		if (queue.empty()) return;
		if (queue.front() == dq.front()) { dq.pop_front(); }
		queue.pop_front();
	}

	int get_min() {
		if (dq.empty()) return -1;
		return dq.front();
	}

	bool empty() { return queue.empty(); }
};

class fqueue {
   private:
	deque<int> dq;
	deque<int> queue;
	function<bool(int, int)> compare;

   public:
	fqueue(function<bool(int, int)> comp = less<int>()) : compare(comp) {}

	void enqueue(int val) {
		while (!dq.empty() && compare(val, dq.back())) { dq.pop_back(); }
		dq.push_back(val);
		queue.push_back(val);
	}

	void dequeue() {
		if (queue.empty()) return;
		if (queue.front() == dq.front()) { dq.pop_front(); }
		queue.pop_front();
	}
	int get() {
		if (dq.empty()) return -1;
		return dq.front();
	}

	int front() {
		if (queue.empty()) return -1;
		return queue.front();
	}

	bool empty() { return queue.empty(); }
};

less<int>()
greater<int>()
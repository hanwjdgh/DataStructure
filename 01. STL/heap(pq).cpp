#include <iostream>

#define MAX_SIZE 100001

using namespace std;

template <typename T>
class PQ {
private:
	int _size = 0;
	T* heap;
public:
	PQ():_size(0), heap(new T[MAX_SIZE]) {}

	void push(T val) {
		heap[_size] = val;

		int cur = _size;

		while (cur > 0 && heap[cur] < heap[(cur - 1) / 2]) {
			int temp = heap[(cur - 1) / 2];
			heap[(cur - 1) / 2] = heap[cur];
			heap[cur] = temp;
			cur = (cur - 1) / 2;
		}

		_size++;
	}

	void pop() {
		_size--;

		heap[0] = heap[_size];
		
		int cur = 0;
		while (cur * 2 + 1 < _size) {
			int child;

			if (cur * 2 + 1 == _size)
				child = cur * 2 + 1;
			else
				child = (heap[cur * 2 + 1] < heap[cur * 2 + 2]) ? cur * 2 + 1 : cur * 2 + 2;

			if (heap[cur] < heap[child])
				break;

			int temp = heap[cur];
			heap[cur] = heap[child];
			heap[child] = temp;

			cur = child;
		}
	}

	T top() {
		return heap[0];
	}

	int size() {
		return _size;
	}

	bool empty() {
		return (_size == 0);
	}
};

int main() {
	PQ <int > pq;

	for (int i = 4; i > -1; i--)
		pq.push(i);

	while (!pq.empty()) {
		cout << "PQ Top : " << pq.top() << " / PQ Size : " << pq.size() << "\n";
		pq.pop();
	}

	return 0;
}
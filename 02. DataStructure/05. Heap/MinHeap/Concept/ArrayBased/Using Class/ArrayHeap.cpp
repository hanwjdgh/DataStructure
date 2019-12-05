#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

class MinHeap {
private:
	int *head;
	int HEAP_SIZE;
	int capacity;
public:
	MinHeap(int size) {
		HEAP_SIZE = 0;
		capacity = size;
		head = new int[size];
	}

	~MinHeap() {
		delete[] head;
	}

	void insertKey(int val) {
		if (HEAP_SIZE == capacity) {
			cout << "Heap is full" << "\n";
			return;
		}
		HEAP_SIZE++;
		int i = HEAP_SIZE - 1;
		head[i] = val;

		while (i != 0 && head[(i - 1) / 2] > head[i]) {
			swap(head[(i - 1) / 2], head[i]);
			i = (i - 1) / 2;
		}
	}

	void deleteKey() {
		if (HEAP_SIZE <= 0)
			return;
		if (HEAP_SIZE == 1) {
			HEAP_SIZE--;
			return;
		}
		int root = head[0];
		head[0] = head[HEAP_SIZE - 1];
		HEAP_SIZE--;
		minHeapify(0);
	}

	void minHeapify(int i) {
		int smallest = i;
		int l = i * 2 + 1;
		int r = i * 2 + 2;

		if (l < HEAP_SIZE && head[l] < head[smallest])
			smallest = l;
		if (r < HEAP_SIZE && head[r] < head[smallest])
			smallest = r;
		if (smallest != i) {
			swap(head[i], head[smallest]);
			minHeapify(smallest);
		}
	}

	int getMin() {
		return head[0];
	}

};

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	MinHeap minheap(10);

	minheap.insertKey(5);
	minheap.insertKey(3);
	minheap.insertKey(2);
	minheap.insertKey(4);
	minheap.insertKey(1);

	cout << minheap.getMin() << "\n";

	minheap.deleteKey();

	cout << minheap.getMin() << "\n";

	return 0;
}
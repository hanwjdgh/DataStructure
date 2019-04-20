#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

class MaxHeap {
private:
	int *head;
	int HEAP_SIZE;
	int capacity;
public:
	MaxHeap(int size) {
		HEAP_SIZE = 0;
		capacity = size;
		head = new int[size];
	}

	~MaxHeap() {
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

		while (i != 0 && head[(i - 1) / 2] < head[i]) {
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
		int largest = i;
		int l = i * 2 + 1;
		int r = i * 2 + 2;

		if (l < HEAP_SIZE && head[l] > head[largest])
			largest = l;
		if (r < HEAP_SIZE && head[r] > head[largest])
			largest = r;
		if (largest != i) {
			swap(head[i], head[largest]);
			minHeapify(largest);
		}
	}

	int getMax() {
		return head[0];
	}

};

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	MaxHeap maxheap(10);

	maxheap.insertKey(5);
	maxheap.insertKey(3);
	maxheap.insertKey(2);
	maxheap.insertKey(4);
	maxheap.insertKey(1);

	cout << maxheap.getMax() << "\n";

	maxheap.deleteKey();

	cout << maxheap.getMax() << "\n";

	return 0;
}
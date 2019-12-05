#include <iostream>
#include <queue> // Use queue Library

using namespace std;

int main() {
	// Declaration int priority queue (= Max heap)
	priority_queue< int, vector<int>, less<int> > pq;
	// = priority_queue<int> pq;

	// Push data
	pq.push(5);
	pq.push(2);
	pq.push(6);
	pq.push(3);
	pq.push(1);
	pq.push(4);
	// top 5 2 6 3 1 4 bottom
	// - > top 6 5 4 3 2 1 bottom

	pq.pop();
	pq.pop();
    // 4 3 2 1
	
	// Print top
	cout << pq.top() << "\n"; //4

	// Print size
	if (!pq.empty()) 
		cout << pq.size() << "\n"; //4

	// Pop data
	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}
	// 4 3 2 1

	return 0;
}
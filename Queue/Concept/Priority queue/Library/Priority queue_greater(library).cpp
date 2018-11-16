#include <iostream>
#include <queue> // Use queue Library
#include <functional> // Use functional Library ( to use greater )

using namespace std;

int main() {
	// Declaration int priority queue (= Min heap)
	priority_queue< int, vector<int>, greater<int> > pq;

	// Push data
	pq.push(5);
	pq.push(2);
	pq.push(6);
	pq.push(3);
	pq.push(1);
	pq.push(4);
	// top 5 2 6 3 1 4 bottom 
	// - > top 1 2 3 4 5 6 bottom

	pq.pop();
	pq.pop();
    // 3 4 5 6
	
	// Print top
	cout << pq.top() << "\n"; // 3

	// Print size
	if (!pq.empty()) 
		cout << pq.size() << "\n"; // 4

	// Pop data
	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}
	// 3 4 5 6
	
	return 0;
}
#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int main() {
	priority_queue< int, vector<int>, greater<int> > pq;


	pq.push(5);
	pq.push(2);
	pq.push(6);
	pq.push(3);
	pq.push(1);
	pq.push(4);

	// 5 2 6 3 1 4 - > 1 2 3 4 5 6
	pq.pop();
	pq.pop();
    // 3 4 5 6
	
	cout << pq.top() << endl; // 3

	if (!pq.empty()) 
		cout << pq.size() << endl; // 4

	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}
	// 3 4 5 6
	return 0;
}
#include <iostream>
#include <queue>

using namespace std;

int main() {
	priority_queue< int, vector<int>, less<int> > pq;
	// priority_queue<int> pq;

	pq.push(5);
	pq.push(2);
	pq.push(6);
	pq.push(3);
	pq.push(1);
	pq.push(4);

	// 5 2 6 3 1 4 - > 6 5 4 3 2 1
	pq.pop();
	pq.pop();
    // 4 3 2 1
	
	cout << pq.top() << endl; //4

	if (!pq.empty()) 
		cout << pq.size() << endl; //4

	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}
	// 4 3 2 1
	return 0;
}
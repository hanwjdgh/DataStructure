#include <iostream>
#include <ios>
#include <queue>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, x;

	cin >> N;
	priority_queue< int, vector<int>, less<int> > pq;

	while (N--) {
		cin >> x;
		if (x == 0) {
			if (!pq.empty()) {
				cout << pq.top() << endl;
				pq.pop();
			}
			else
				cout << "0" << endl;
		}
		else
			pq.push(x);
	}
	return 0;
}
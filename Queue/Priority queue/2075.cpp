#include <iostream>
#include <ios>
#include <queue>
#include <functional>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, x;

	cin >> N;
	priority_queue< int, vector<int>, greater<int> > pq;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> x;
			if (pq.size() < N)
				pq.push(x);
			else if(pq.size()==N){
				if (pq.top() < x) {
					pq.pop();
					pq.push(x);
				}
			}
		}
	}
	cout << pq.top() << endl;
	return 0;
}
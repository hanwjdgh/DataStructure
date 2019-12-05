#include <iostream>
#include <ios>
#include <queue>
#include <functional>
#include <cmath>

using namespace std;
typedef pair <int, int> p;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	priority_queue< p, vector<p >, greater<p > > pq;

	cin >> N;

	while (N--) {
		int x;

		cin >> x;
		if (x == 0) {
			if (pq.empty())
				cout << "0" << endl;
			else {
				cout << pq.top().second << endl;
				pq.pop();
			}
		}
		else
			pq.push({ abs(x),x });
	}
	return 0;
}
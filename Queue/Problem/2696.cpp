#include <iostream>
#include <ios>
#include <queue>
#include <functional>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T, M;

	cin >> T;

	while (T--) {
		priority_queue <int, vector<int >, less<int > > max_pq;
		priority_queue <int, vector<int >, greater<int > > min_pq;
		int num;

		cin >> M;

		cout << (M + 1) / 2 << endl;

		for (int i = 0; i < M; i++) {
			cin >> num;

			int max_q_s = max_pq.size();
			int min_q_s = min_pq.size();

			if (max_q_s == min_q_s) {
				if (max_q_s == 0)
					max_pq.push(num);
				else {
					if (min_pq.top() <= num) {
						int temp = min_pq.top();
						min_pq.pop();
						min_pq.push(num);
						max_pq.push(temp);
					}
					else
						max_pq.push(num);
				}
			}
			else {
				if (max_pq.top() > num) {
					int temp = max_pq.top();
					max_pq.pop();
					max_pq.push(num);
					min_pq.push(temp);
				}
				else
					min_pq.push(num);
			}

			if (i % 2 == 0)
				cout << max_pq.top() << " ";
		}
		cout << endl;
	}
	return 0;
}
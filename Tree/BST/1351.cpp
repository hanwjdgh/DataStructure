#include <iostream>
#include <ios>
#include <map>

using namespace std;

map <long long, long long > m;
long long N, P, Q;

long long find(long long cur) {
	if (cur == 0)
		return 1;
	if (m[cur] != 0)
		return m[cur];
	return m[cur] = find(cur / P) + find(cur / Q);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> P >> Q;

	cout << find(N) << "\n";
	return 0;
}
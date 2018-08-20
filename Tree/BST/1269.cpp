#include <iostream>
#include <ios>
#include <set>

using namespace std;

set <int > s;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	int n, m, a,chk=0;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a;
		s.insert(a);
	}

	for (int i = 0; i < m; i++) {
		cin >> a;
		if (s.find(a) != s.end())
			chk++;
	}
	cout << n + m - 2 * chk << "\n";
	return 0;
}
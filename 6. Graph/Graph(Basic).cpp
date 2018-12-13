#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main() {
	int s, e, n, l;
	/*
	4 4
	1 2
	1 4
	3 4
	2 4
	*/
	cin >> n >> l;

	vector < list < int > > head(n + 1);

	for (int i = 0; i < l; i++) {
		cin >> s >> e;
		head[s].push_back(e);
		head[e].push_back(s);
	}

	for (int i = 1; i <= n; i++) {
		cout << i << " : ";

		if (!head[i].empty())
			for (auto x : head[i])
				cout << x << " ";

		cout << endl;
	}
	/*
	1 : 2 4
	2 : 1 4
	3 : 4
	4 : 1 3 2
	*/
	return 0;
}

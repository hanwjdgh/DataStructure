#include <iostream>
#include <ios>
#include <vector>

using namespace std;

vector <int > v[26];

void pre_order(int cur) {
	if (cur == -1)
		return;
	cout << char(cur+'A');
	for (int i = 0; i < v[cur].size(); i++)
		pre_order(v[cur][i]);
}

void in_order(int cur) {
	if (cur == -1)
		return;
	if (v[cur].size() == 0)
		cout << char(cur + 'A');
	for (int i = 0; i < v[cur].size(); i++) {
		in_order(v[cur][i]);
		if (i == 0)
			cout << char(cur + 'A');
	}
}

void post_order(int cur) {
	if (cur == -1)
		return;
	for (int i = 0; i < v[cur].size(); i++)
		post_order(v[cur][i]);
	cout << char(cur + 'A');
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	char a, b, c;

	cin >> N;

	while (N--) {
		cin >> a >> b >> c;
		if (b != '.')
			v[a - 'A'].push_back(b - 'A');
		else
			v[a - 'A'].push_back(-1);

		if (c != '.')
			v[a - 'A'].push_back(c - 'A');
		else
			v[a - 'A'].push_back(-1);
	}
	pre_order(0);
	cout << endl;
	in_order(0);
	cout << endl;
	post_order(0);
	return 0;
}
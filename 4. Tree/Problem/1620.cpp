#include <iostream>
#include <ios>
#include <string>
#include <map>

#define MAX 100001

using namespace std;

map <string, int > mp;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m, a;
	string str[MAX], tmp;

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		str[i] = tmp;
		mp[tmp] = i;
	}

	for (int i = 0; i < m; i++) {
		cin.ignore(1);
		if (isdigit(cin.peek())) {
			cin >> a;
			cout << str[a] << "\n";
		}
		else {
			cin >> tmp;
			cout << mp[tmp] << "\n";
		}
	}
	return 0;
}
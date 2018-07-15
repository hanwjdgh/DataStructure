#include <iostream>
#include <cstdio>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int T;

	cin >> T;
	for (int i = 0; i < T; i++) {
		string func, arr, tmp;
		int leng;
		deque <string> d;

		cin >> func >> leng;

		while (1) {
			char c = getchar();
			if (c >= '0' && c <= '9')
				tmp += c;
			else {
				if (tmp.length() > 0)
					d.push_back(tmp);
				tmp.clear();
				if (c == ']')
					break;
			}
		}

		int len = func.length();
		bool error = false, chk = false;
		for (int i = 0; i < len; i++) {
			if (func[i] == 'R')
				chk = !chk;
			else {
				if (d.empty()) {
					error = true;
					break;
				}
				if (chk)
					d.pop_back();
				else 
					d.pop_front();
			}
		}
		if (error)
			cout << "error" << endl;
		else {
			cout << '[';
			if (chk)
				reverse(d.begin(), d.end());
			for (int i = 0; i < d.size(); i++) {
				cout << d[i];
				if (i < d.size() - 1)
					cout << ',';
			}
			cout << ']' << endl;
		}
	}
	return 0;
}
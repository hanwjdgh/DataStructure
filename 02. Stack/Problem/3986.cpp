#include <iostream>
#include <cstdio>
#include <stack>
#include <string>

using namespace std;

int main() {
	int N, cnt = 0;
	string str;

	cin >> N;
	for (int i = 0; i < N; i++) {
		stack <int> s;

		cin >> str;
		int len = str.length();
		for (int j = 0; j < len; j++) {
			if (s.empty() || s.top() != str[j]) {
				s.push(str[j]);
				continue;
			}
			if (!s.empty() && s.top() == str[j]) 
				s.pop();
		}
		if (s.empty())
			cnt++;
	}
	printf("%d", cnt);
	return 0;
}
#include <iostream>
#include <cstdio>
#include <stack>
#include <string>

using namespace std;

int main() {
	string str;
	int C;

	scanf("%d", &C);
	while (C--) {
		stack <char> st;
		cin >> str;
		for (int i = 0; i < str.length(); i++) {
			if (st.empty())
				st.push(str[i]);
			else {
				if (str[i] == ')' && st.top() == '(')
					st.pop();
				else
					st.push(str[i]);
			}
		}
		if (st.empty())
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
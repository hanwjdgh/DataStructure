#include <iostream>
#include <cstdio>
#include <string>
#include <stack>

using namespace std;

stack <int> st;

int main() {
	string str;
	
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'A'&&str[i] <= 'Z')
			printf("%c", str[i]);
		else {
			if (str[i] == '(')
				st.push(str[i]);
			else if (str[i] == ')') {
				while (st.top()!='(') {
					printf("%c", st.top());
					st.pop();
				}
				st.pop();
			}
			else if (str[i] == '+' || str[i] == '-') {
				while (!st.empty() && st.top() != '(') {
					printf("%c", st.top());
					st.pop();
				}
				st.push(str[i]);
			}
			else {
				while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
					printf("%c", st.top());
					st.pop();
				}
				st.push(str[i]);
			}
		}
	}
	while (!st.empty()) {
		printf("%c", st.top());
		st.pop();
	}
	return 0;
}
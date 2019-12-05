#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#include <vector>

using namespace std;

stack <double> st;
vector <double> v;

int main() {
	int N, cnt = 0;
	double a, b, num;
	string str;

	scanf("%d", &N);
	cin >> str;
	for (int i = 0; i < N; i++) {
		scanf("%lf", &num);
		v.push_back(num);
	}

	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'A'&&str[i] <= 'Z')
			st.push(v[str[i]-'A']);
		else {
			a = st.top();
			st.pop();
			b = st.top();
			st.pop();

			switch (str[i]) {
			case '+':
				st.push(b + a);
				break;
			case '-':
				st.push(b - a);
				break;
			case '*':
				st.push(b * a);
				break;
			case '/':
				st.push(b / a);
				break;
			default:
				break;
			}
		}
	}
	printf("%.2lf", st.top());
	return 0;
}
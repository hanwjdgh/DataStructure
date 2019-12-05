#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

stack <long long > s;
vector <long long > v;

int main() {
	int N;
	long long num, i;
	long long max_v = 0;

	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> num;
		v.push_back(num);
		if (i == 0) {
			s.push(i);
			continue;
		}
		while (!s.empty() && v[s.top()] >= v[i]) {
			long long val = s.top();
			s.pop();
			if (!s.empty()) 
				max_v = max(max_v, v[val] * (i - s.top() - 1));
			else 
				max_v = max(max_v, v[val] * i);
			
		}
		s.push(i);
	}
	while (!s.empty()) {
		long long val = s.top();
		s.pop();
		if (!s.empty())
			max_v = max(max_v, v[val] * (i - s.top() - 1));
		else
			max_v = max(max_v, v[val] * i);

	}
	printf("%lld", max_v);
	return 0;
}
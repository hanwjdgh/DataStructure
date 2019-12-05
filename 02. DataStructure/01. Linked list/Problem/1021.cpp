#include <iostream>
#include <cstdio>
#include <list>
#include <vector>

using namespace std;

vector <int> v;
list <int> lst;

int main() {
	int N, M;
	int num,temp;
	int cnt = 0;
	list<int>::iterator it;
	list<int>::reverse_iterator rt;

	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &num);
		v.push_back(num);
	}
	for (int i = 1; i <= N; i++)
		lst.push_back(i);

	for (int i = 0; i < M; i++) {
		if (lst.front() == v[i]) {
			lst.pop_front();
			continue;
		}
		else {
			int left=0, right = 0;
			for (it = lst.begin(); it != lst.end(); it++) {
				if (*it == v[i])
					break;
				left++;
			}
			for (rt = lst.rbegin(); rt != lst.rend(); rt++) {
				if (*rt == v[i])
					break;
				right++;
			}

			if (left <= right) {
				for (int i = 0; i < left; i++) {
					temp = lst.front();
					lst.pop_front();
					lst.push_back(temp);
					cnt++;
				}
			}
			else {
				for (int i = 0; i <= right; i++) {
					temp = lst.back();
					lst.pop_back();
					lst.push_front(temp);
					cnt++;
				}
			}
		}
		lst.pop_front();
	}
	printf("%d\n", cnt);
	return 0;
}
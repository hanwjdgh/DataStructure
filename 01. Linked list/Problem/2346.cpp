#include <iostream>
#include <cstdio>
#include <list>
#include <vector>

using namespace std;

list <pair<int,int> > lst;
pair <int, int> p;

int main(void) {
	int N;
	int num;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		lst.push_back(make_pair(num, i));
	}
	
	for (int i = 0; i < N; i++) {
		if (i == 0) {
			p = lst.front();
			lst.pop_front();
			printf("%d ", p.second + 1);
		}
		else {
			int temp = p.first;
			if (temp > 0) {
				for (int j = 0; j < temp-1; j++) {
					p = lst.front();
					lst.pop_front();
					lst.push_back(p);
				}
			}
			else {
				temp *= -1;
				for (int j = 0; j < temp; j++) {
					p = lst.back();
					lst.pop_back();
					lst.push_front(p);
				}
			}
			p = lst.front();
			lst.pop_front();
			printf("%d ", p.second + 1);
		}
	}
	return 0;
}
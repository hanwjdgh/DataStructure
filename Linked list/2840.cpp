#include <iostream>
#include <cstdio>
#include <list>
#include <vector>

using namespace std;

pair <int, char> p;
list <pair<int, char> > lst;
vector <char> v;

int main(void) {
	int N, K, cnt = 0;
	int num, alpha[26] = { 0, }, temp;
	char c, tp, it;

	scanf("%d %d", &N, &K);
	list <char> arr(N, 'a');

	for (int i = 0; i < K; i++) {
		scanf("%d %c", &num, &c);
		lst.push_back(make_pair(num, c));
	}

	for (int i = 0; i < K; i++) {
		p = lst.front();
		lst.pop_front();
		temp = p.first;
		it = p.second;

		for (int j = 0; j < temp; j++) {
			tp = arr.front();
			arr.pop_front();
			arr.push_back(tp);
		}
		if (arr.front() == 'a') {
			if (alpha[it - 'A'] == 1) {
				printf("!");
				cnt++;
				break;
			}
			else {
				arr.pop_front();
				arr.push_front(it);
				alpha[it - 'A'] = 1;
			}
		}
		else {
			if (arr.front() == it)
				continue;
			else {
				printf("!");
				cnt++;
				break;
			}
		}
	}

	if (cnt == 0) {
		for (list<char >::iterator it = arr.begin(); it != arr.end(); it++) {
			v.push_back(*it);
		}
		printf("%c", v[0]);
		for (int i = N-1; i > 0; i--) {
			if (v[i] == 'a')
				printf("?");
			else
				printf("%c", v[i]);
		}
	}
	/*
	for (list<pair<int, char>>::iterator it = lst.begin(); it != lst.end(); it++) {
		printf("%d %c\n", (*it).first, (*it).second);
	}*/
	return 0;
}
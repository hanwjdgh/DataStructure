#include <iostream>
#include <cstdio>
#include <list>
#include <string>

using namespace std;

int main(void) {
	int N;
	char a, b;

	list<char>::iterator it;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		list <char> lst;
		string arr;

		cin >> arr;

		list<char>::iterator it;
		it = lst.begin();

		for (int i = 0; i < arr.size(); i++) {
			switch (arr[i]) {
			case '-':
				if (it != lst.begin()) {
					it--;
					it = lst.erase(it);
				}
				break;
			case '<':
				if (it != lst.begin())
					it--;
				break;
			case '>':
				if (it != lst.end())
					it++;
				break;
			default:
				lst.insert(it, arr[i]);
				break;
			}
		}

		for (list<char>::iterator it = lst.begin(); it != lst.end(); it++)
			printf("%c", *it);
		printf("\n");
	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <list>

using namespace std;

list <int> lst;

int main(void) {
	int N, M;

	scanf("%d %d", &N, &M);
	
	int a;
	for (a = 1; a <= N; ++a)
		lst.push_back(a);

	printf("<");
	while (!lst.empty()) {
		for (a = 0; a < M - 1; ++a) {
			lst.push_back(lst.front());
			lst.pop_front();
		}
		printf("%d", lst.front());
		lst.pop_front();
		if (!lst.empty())
			printf(", ");
	}
	printf(">");
	return 0;
}
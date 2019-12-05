#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

stack <int> s;

int main() {
	int n;
	int adding;
	char input[100];

	scanf("%d", &n);

	while (n--) {
		scanf("%s", input);

		if (!strcmp("push", input)) {
			scanf("%d", &adding);
			s.push(adding);
		}
		else if (!strcmp("pop", input)) {
			if (s.empty()) {
				printf("-1\n");
				continue;
			}
			printf("%d\n", s.top());
			s.pop();
		}
		else if (!strcmp("size", input)) {
			printf("%d\n", s.size());
		}
		else if (!strcmp("empty", input)) {
			if (s.empty()) {
				printf("1\n");
				continue;
			}
			printf("0\n");
		}
		else if (!strcmp("top", input)) {
			if (s.empty()) {
				printf("-1\n");
				continue;
			}
			printf("%d\n", s.top());
		}
	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

queue <int> q;

int main() {
	int n;
	int adding;

	scanf("%d", &n);
	char input[100];

	while (n--) {
		scanf("%s", input);

		if (!strcmp("push", input)) {
			scanf("%d", &adding);
			q.push(adding);
		}
		else if (!strcmp("pop", input)) {
			if (q.empty()) {
				printf("-1\n");
				continue;
			}
			printf("%d\n", q.front());
			q.pop();
		}

		else if (!strcmp("size", input)) {
			printf("%d\n", q.size());
		}

		else if (!strcmp("empty", input)) {
			if (q.empty()) {
				printf("1\n");
				continue;
			}
			printf("0\n");
		}

		else if (!strcmp("front", input)) {
			if (q.empty()) {
				printf("-1\n");
				continue;
			}
			printf("%d\n", q.front());
		}
		else if (!strcmp("back", input)) {
			if (q.empty()) {
				printf("-1\n");
				continue;
			}
			printf("%d\n", q.back());
		}
	}
	return 0;
}
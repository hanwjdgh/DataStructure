#include <cstdio>

int main() {
	int N;
	int cnt = 0;

	scanf("%d", &N);
	while (1) {

		if (N == 0) break;
		else if (N < 0) {
			cnt = -1;
			break;
		}
		else if (N % 5 == 0) {
			N = N - 5;
			cnt++;
		}
		else if (N % 3 == 0) {
			N = N - 3;
			cnt++;
		}
		else if (N % 5 != 0 && N % 3 != 0) {
			N = N - 5;
			cnt++;
		}
	}
	printf("%d", cnt);
}
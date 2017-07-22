#include <cstdio>
#include <algorithm>
using namespace std;
int main(void) {
	int num, a, sum = 0;
	int arr[10001];
	scanf("%d", &num);
	for (a = 0; a < num; a++) {
		scanf("%d", &arr[a]);
	}
	sort(arr, arr + num);
	for (a = 0; a < num; a++) {
		if ((sum += arr[a] - a) < 0) {
			printf("-1");
			return 0;
		}
	}
	printf("%d", sum ? -1 : 1);
	return 0;
}
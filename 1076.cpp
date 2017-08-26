#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int main(void) {
	char str[10][10] = { "black","brown","red","orange","yellow","green","blue","violet","grey","white" };
	char tem[10];
	int f = 10, s = 1;
	long long te = 0;
	for (int a = 0; a < 3; a++) {
		scanf("%s", tem);
		for (int b = 0; b < 10; b++) {
			if (strcmp(str[b], tem) == 0) {
				switch (a) {
				case 0:
					f *= b;
					break;
				case 1:
					s *= b;
					break;
				case 2:
					te = (long long)pow(10, b);
					break;
				default:
					break;
				}
			}
		}
	}
	printf("%lld\n", (f + s)*te);
	return 0;
}
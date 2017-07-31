#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int main(void) {
	int num = 0, a, cnt = 0;
	string str;
	while (num<8) {
		getline(cin, str);
		if (num % 2 == 0) {
			for (a = 0; a < str.length(); a++) {
				if (a % 2 == 0 && str[a] == 'F')
					++cnt;
			}
		}
		else {
			for (a = 0; a < str.length(); a++) {
				if (a % 2 == 1 && str[a] == 'F')
					++cnt;
			}
		}
		num++;
	}
	printf("%d", cnt);
	return 0;
}
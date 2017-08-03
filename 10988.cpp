#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main(void) {
	int a, chk = 1;
	int len;
	string str;
	getline(cin, str);
	len = str.length();
	for (a = 0; a < len / 2; a++) {
		if (str.at(a) != str.at(len - 1 - a))
			chk = 0;
	}
	printf("%d", chk ? 1 : 0);
	return 0;
}
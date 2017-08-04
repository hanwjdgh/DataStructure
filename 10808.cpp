#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main(void) {
	int a, arr[26];
	string str;
	getline(cin, str);
	fill(arr, arr + 26, 0);
	for (a = 0; a < str.length(); a++) {
		arr[str.at(a) - 'a']++;
	}
	for (a = 0; a < 26; a++)
		printf("%d ", arr[a]);
	return 0;
}
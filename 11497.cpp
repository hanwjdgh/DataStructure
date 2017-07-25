#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int num, cnum, var;
	int a;

	cin >> num;

	while (num--) {
		var = 0;
		cin >> cnum;
		int *arr = new int[cnum];
		for (a = 0; a < cnum; a++)
			cin >> arr[a];
		sort(arr, arr + cnum);
		for (a = 2; a < cnum; a++)
			var = max(var, arr[a] - arr[a - 2]);

		cout << var << endl;
	}

	return 0;
}
#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string str;
	while (1){
		getline(cin, str);
		if (str == "")
			break;
		cout << str << '\n';
	}
	return 0;
}
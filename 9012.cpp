#include <iostream> 
#include <string>
using namespace std;
int main() {
	string str;
	int chk;
	int C;
	cin >> C;
	while (C--) {
		chk = 0;
		str = "";
		cin >> str;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '(')
				chk++;
			else chk--;
			if (chk < 0)
				break;
		}
		if (chk == 0)
			cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
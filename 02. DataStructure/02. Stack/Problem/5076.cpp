#include <iostream>
#include <cstdio>
#include <stack>
#include <string>

using namespace std;

int main() {
	string str;

	while (1) {
		stack <string> s;
		getline(cin, str);
		if (str == "#")
			break;
		
		int len = str.length();
		int chk = 0,cnt=0;
		string arr = "";

		for (int i = 0; i < len; i++) {
			if (str[i] == '<') {
				chk = 1;
				continue;
			}
			if (chk == 1) {
				if (str[i] == '>' || str[i] == ' ') {
					chk = 0;
					if (arr != "br") {
						if (s.empty())
							s.push(arr);
						else {
							if (s.top() != arr)
								s.push(arr);
							else
								s.pop();
						}
					}
					arr = "";
				}
				else {
					if(str[i]!='/')
						arr += str[i];
				}
			}
		}
		if (s.empty())
			printf("legal\n");
		else
			printf("illegal\n");
	}
	return 0;
}
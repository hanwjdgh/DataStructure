#include <iostream>
#include <cstdio>
#include <list>
#include <string>

using namespace std;

list <char> lst;

int main(void) {
	int N;
	char a, b;
	string arr;
	list<char>::iterator it;

	cin >> arr;
	for (int i = 0; i < arr.size(); i++) 
		lst.push_back(arr[i]);
	
	it = lst.end();

	scanf("%d%*c", &N);
	for (int i = 0; i < N; i++) {
		scanf("%c%*c", &a);
		switch (a){
		case 'P':
			scanf("%c%*c", &b);
			lst.insert(it, b);
			break;
		case 'L':
			if (it != lst.begin())
				it--;
			break;
		case 'D':
			if (it != lst.end())
				it++;
			break;
		case 'B':
			if (it != lst.begin())
				it--;
			else
				continue;
			it = lst.erase(it);
			break;
		default:
			break;
		}
	}

	for (it = lst.begin(); it != lst.end(); it++)
		printf("%c", *it);
	printf("\n");
    
	return 0;
}
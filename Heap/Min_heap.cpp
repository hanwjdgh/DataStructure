#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int heap[10];
	int n,m;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> m;
		heap[i] = m;
		for (int j = i; j > 1; j /= 2) {
			if (heap[j] > heap[j / 2]) {
				swap(heap[j], heap[j / 2]);
			}
		}
	}
	// 8 3 5 7 11 6

	for (int i = 1; i <= n; i++) {
		swap(heap[1], heap[n - i + 1]);
		for (int j = 1; ; ) {
			int k = j * 2;
			if (k > n - i) 
				break;
			if (k + 1 <= n - i && heap[k] < heap[k + 1]) 
				k++;
			if (heap[j] < heap[k]) {
				swap(heap[j], heap[k]);
				j = k;
			}
			else 
				break;
		}

	}

	for (int i = 1; i <= n; i++)
		cout << heap[i] << " ";
	// 3 5 6 7 8 11
	return 0;
}
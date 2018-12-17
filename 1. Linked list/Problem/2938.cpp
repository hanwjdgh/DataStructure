#include <iostream>
#include <ios>
#include <cstdlib>
#include <string>
#include <algorithm>

#define MAX 100001

using namespace std;

typedef struct node {
	int tmp;
	int orgin_idx;
	node *prev, *next;
}Node;

typedef struct plant {
	int x, y;
	Node *sp, *dp;
}Plant;

Plant arr[MAX];
int temp[MAX];

bool cmpf(int i, int j) { return (arr[i].sp->tmp != arr[j].sp->tmp) ? arr[i].sp->tmp < arr[j].sp->tmp : arr[i].x < arr[j].x; }
bool cmps(int i, int j) { return (arr[i].dp->tmp != arr[j].dp->tmp) ? arr[i].dp->tmp < arr[j].dp->tmp : arr[i].x < arr[j].x; }

Node *head, *tail, *dhead, *dtail;

void deleteNode(Node *node) {
	if (head == node || dhead == node) {
		if (head == node) {
			node->next->prev = NULL;
			head = node->next;
		}
		else {
			node->next->prev = NULL;
			dhead = node->next;
		}
	}
	else if (tail == node || dtail == node) {
		if (tail == node) {
			node->prev->next = NULL;
			tail = node->prev;
		}
		else {
			node->prev->next = NULL;
			dtail = node->prev;
		}
	}
	else {
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	delete node;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, K;
	string dir;

	cin >> N >> K >> dir;

	for (int i = 0; i < N; i++) {
		cin >> arr[i].x >> arr[i].y;
		temp[i] = i;
	}

	for (int i = 0; i < N; i++) {
		arr[i].sp = (Node *)malloc(sizeof(Node));
		arr[i].sp->tmp = arr[i].x + arr[i].y;
		arr[i].sp->prev = arr[i].sp->next = NULL;

		arr[i].dp = (Node *)malloc(sizeof(Node));
		arr[i].dp->tmp = arr[i].x - arr[i].y;
		arr[i].dp->prev = arr[i].dp->next = NULL;
	}
	sort(temp, temp + N, cmpf);
	for (int i = 0; i < N; i++) {
		arr[temp[i]].sp->orgin_idx = temp[i];
		if (!head)
			head = tail = arr[temp[i]].sp;
		else {
			Node *cur = tail;
			cur->next = arr[temp[i]].sp;
			arr[temp[i]].sp->prev = cur;
			tail = arr[temp[i]].sp;
		}
	}
	sort(temp, temp + N, cmps);
	for (int i = 0; i < N; i++) {
		arr[temp[i]].dp->orgin_idx = temp[i];
		if (!dhead)
			dhead = dtail = arr[temp[i]].dp;
		else {
			Node *cur = dtail;
			cur->next = arr[temp[i]].dp;
			arr[temp[i]].dp->prev = cur;
			dtail = arr[temp[i]].dp;
		}
	}
	int start = 0;
	for (int i = 0; i < dir.length(); i++) {
		Node *cur;
		if (dir[i] == 'A' || dir[i] == 'D')
			cur = arr[start].dp;
		else
			cur = arr[start].sp;

		int tp = cur->tmp;
		int tidx;

		if (dir[i] == 'A' || dir[i] == 'B') {
			if ((dir[i] == 'A' && cur == dtail) || (dir[i] == 'B' && cur == tail))
				continue;
			if (cur->tmp != cur->next->tmp)
				continue;
			tidx = cur->next->orgin_idx;
			deleteNode(arr[start].sp);
			deleteNode(arr[start].dp);
		}
		else {
			if ((dir[i] == 'D' && cur == dhead) || (dir[i] == 'C' && cur == head))
				continue;
			if (cur->tmp != cur->prev->tmp)
				continue;
			tidx = cur->prev->orgin_idx;
			deleteNode(arr[start].sp);
			deleteNode(arr[start].dp);
		}
		start = tidx;

	}
	cout << arr[start].x << " " << arr[start].y << "\n";
	return 0;
}
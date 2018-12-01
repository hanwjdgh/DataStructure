#include <iostream>
#include <ios>
#include "LinkedListDQ.h"

using namespace std;

int main(){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

    DQueue queue;
    
    init(&queue);

    pushFront(&queue,1);
    pushFront(&queue,2);
    pushRear(&queue,3);
    pushRear(&queue,4);
    
    return 0;
}
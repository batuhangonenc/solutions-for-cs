#include "map.h"
#include "stack.h"
#include "queue.h"
#include "linkedlist.h"
#include "doublylinkedlist.h"
#include "circularlinkedlist.h"

int main(){
	int arr[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	map<int> m;

	m.push("r1", 1);
	m.push("r2", 2);
	m.push("r3", 3);
	m.push("r4", 4);
	m.push("r5", 5);

	m["r1"] = 31;
	m.print();
	
	queue<int> q(arr, 10);

	q.print();
	LinkedList<int> ll(arr, 10);

	ll.print();


return 0;
}

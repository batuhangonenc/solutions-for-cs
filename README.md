### Guide for Structures

#### Linked List Methods

- erase(), frees all the memory that using by it.

- print (), prints linked list to end by root.

- reverse (), prints linked list to root by end.

- change_at ( int pos, datatype arg ), changes the value of node in the position to given arg.

- push_front ( datatype arg ), adds a node with arg to front of the list.

- push_end ( datatype arg ), adds a node with arg to end of the list.

- delete_at ( int pos ), deletes the node in position from list. 

- concat ( node* new_root ), links last node of current list to the new_root.

- insert ( node* new_root, int pos ), links the node in position to the new_root and links the last element of new linked list to next element of the node in position.

#### Doubly Linked List Methods

- erase(), frees all the memory that using by it.

- print (), prints doubly linked list to end by root.

- reverse (), prints doubly linked list to root by end.

- change_at ( datatype arg, int pos ), changes the value of node in the position to given arg.

- push_front ( datatype arg ), adds a node with arg to front of the list.

- push_end ( datatype arg ), adds a node with arg to end of the list.

- delete_at ( int pos ), removes the node in position from list. 

- concat ( node* new_root ), links last node of current list to the new_root.

- insert ( node* new_root, int pos ), links the node in position to the new_root and links the last element of new linked list to next element of the node in position.


#### Circular Linked List Methods
- erase(), frees all the memory using by it.

- print (), prints circular linked list to end by head.

- push ( datatype arg ), adds a new node with arg to circular linked list.

- delete_at ( int pos ), removes the node in position from circular linked list.

- insert ( node* new_head, int pos ), links the node in position to new_head and links the last element of new circular or normal linked list to the next element of the node in position. 
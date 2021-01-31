### Guide for Structures

#### Linked List Methods

- erase (), frees all the memory that using by it.

- print (), prints linked list to end by root.

- reverse (), prints linked list to root by end.

- change_at ( int pos, datatype arg ), changes the value of node in the position to given arg.

- void swap ( int pos1, int pos2 ), assign the data in pos1 to pos2, and pos2 to pos1.

- push_front ( datatype arg ), adds a node with arg to front of the list.

- push_end ( datatype arg ), adds a node with arg to end of the list.

- delete_at ( int pos ), deletes the node in position from list. 

- concat ( node* new_root ), links last node of current list to the new_root.

- insert ( node* new_root, int pos ), links the node in position to the new_root and links the last element of new linked list to next element of the node in position.

#### Doubly Linked List Methods

- void erase (), frees all the memory that using by it.

- void print (), prints doubly linked list to end by root.

- void reverse (), prints doubly linked list to root by end.

- void change_at ( datatype arg, int pos ), changes the value of node in the position to given arg.

- void push_front ( datatype arg ), adds a node with arg to front of the list.

- void push_end ( datatype arg ), adds a node with arg to end of the list.

- void delete_at ( int pos ), removes the node in position from list. 

- void concat ( node* new_root ), links last node of current list to the new_root.

- insert ( node* new_root, int pos ), links the node in position to the new_root and links the last element of new linked list to next element of the node in position.


#### Circular Linked List Methods
- void erase (), frees all the memory using by it.

- void print (), prints circular linked list to end by head.

- void push ( datatype arg ), adds a new node with arg to circular linked list.

- void delete_at ( int pos ), removes the node in position from circular linked list.

- void insert ( node* new_head, int pos ), links the node in position to new_head and links the last element of new circular or normal linked list to the next element of the node in position. 

#### Stack(LIFO) Methods

- void erase (), frees all the memory using by it.

- void print (), prints stack by top to end.

- void push ( dt arg ), add a new node with 'arg' to top of the stack. 

- void pop (), removes the node in top from stack.

- void swap ( int pos1, int pos2 ), assign the data in pos1 to pos2, and pos2 to pos1.

- bool is_empty (), tells whether the stack empty.  

- dt top (), gives the data at the node in top.

#### Queue(FIFO) Methods

- void erase (), frees all the memory using by it.

- void print (), prints queue by front to back.

- void push ( dt arg ), add a new node with 'arg' to queue. 

- void pop (), removes next node from queue.

- void swap ( int pos1, int pos2 ), assign the data in pos1 to pos2, and pos2 to pos1.

- dt front (), gives the data at the next node.  

- dt back (), gives the data at the last node.

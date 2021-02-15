### Guide for Structures

#### Linked List Methods

- datatype at ( const int& pos ), returns the value stored in the node in position.

- void erase (), frees all the memory that using by it.

- void print (), prints linked list to end by root.

- void reverse (), prints linked list to root by end.

- void change_at ( const int& pos, const datatype& arg ), changes the value of node in the position to given arg.

- void swap ( const int& pos1, const int& pos2 ), assign the data in pos1 to pos2, and pos2 to pos1.

- void push_front ( const datatype& arg ), adds a node with arg to front of the list.

- void push_end ( const datatype& arg ), adds a node with arg to end of the list.

- void delete_at ( const int& pos ), deletes the node in position from list. 

- void concat ( node* new_root ), links last node of current list to the new_root.

- void insert ( node* new_root, int pos ), links the node in position to the new_root and links the last element of new linked list to next element of the node in position.

#### Doubly Linked List Methods

- datatype at ( const int& pos ), returns the value stored in the node in position.

- void erase (), frees all the memory that using by it.

- void print (), prints doubly linked list to end by root.

- void reverse (), prints doubly linked list to root by end.

- void change_at ( const datatype& arg, const int& pos ), changes the value of node in the position to given arg.

- void push_front ( const datatype& arg ), adds a node with arg to front of the list.

- void push_end ( const datatype& arg ), adds a node with arg to end of the list.

- void delete_at ( const int& pos ), removes the node in position from list. 

- void concat ( node* new_root ), links last node of current list to the new_root.

- insert ( node* new_root, int pos ), links the node in position to the new_root and links the last element of new linked list to next element of the node in position.


#### Circular Linked List Methods
- void erase (), frees all the memory using by it.

- void print (), prints circular linked list to end by head.

- void push ( const datatype& arg ), adds a new node with arg to circular linked list.

- void delete_at ( const int& pos ), removes the node in position from circular linked list.

- void insert ( node* new_head, int pos ), links the node in position to new_head and links the last element of new circular or normal linked list to the next element of the node in position. 

#### Stack(LIFO) Methods

- void erase (), frees all the memory using by it.

- void print (), prints stack by top to end.

- void push ( const datatype& arg ), add a new node with 'arg' to top of the stack. 

- void pop (), removes the node in top from stack.

- void swap ( int pos1, int pos2 ), assign the data in pos1 to pos2, and pos2 to pos1.

- bool is_empty (), tells whether the stack empty.  

- datatype top (), gives the data at the node in top.

- void delete_at ( const int& pos ), removes the node in position from list. 


#### Queue(FIFO) Methods

- void erase (), frees all the memory using by it.

- void print (), prints queue by front to back.

- void push ( const datatype& arg ), add a new node with 'arg' to queue. 

- void pop (), removes next node from queue.

- void swap ( const int& pos1, const int& pos2 ), assign the data in pos1 to pos2, and pos2 to pos1.

- datatype front (), gives the data at the next node.  

- datatype back (), gives the data at the last node.

- void delete_at ( const int& pos ), removes the node in position from list. 

#### Map Methods

- void erase (), frees all the memoru using by it.

- void print (), prints queue by front to back.

- void push ( const string& key, const datatype& arg ), add a new node with 'arg' to queue. 

- void remove ( const string& key ), remove the node with key.

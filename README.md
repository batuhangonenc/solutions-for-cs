### GINT ! an integer with unlimited bases!
#### constructor:
##### gint( const int& size, const char& ch)
##### memset( data, ch, size)
#### there is only one function named 'add' now.
#### it accepts one paramater as int.
 
### Guide for Structures

#### Linked List Methods

- datatype at ( const int&), returns the value stored in the node in position.

- void erase (), frees all the memory that using by its nodes.

- void print (), prints linked list to end by root.

- void reverse (), prints linked list to root by end.

- void change_at ( const int&, const datatype&  ), changes the value of node in the position to given arg.

- void swap ( const int&, const int& ), assign the data in pos1 to pos2, and pos2 to pos1.

- void push_front ( const datatype& ), adds a node with arg to front of the list.

- void push_end ( const datatype& ), adds a node with arg to end of the list.

- void delete_at ( const int& ), deletes the node in position from list. 

- void concat ( const LinkedList& ), links last node of current list to the new_root.


#### Stack(LIFO) Methods

- void erase (), frees all the memory using by its nodes.

- void print (), prints stack by top to end.

- void push ( const datatype& ), add a new node with 'arg' to top of the stack. 

- void pop (), removes the node in top from stack.

- void swap ( const int&, const int& ), assign the data in pos1 to pos2, and pos2 to pos1.

- bool is_empty (), tells whether is the stack empty.  

- datatype top (), gives the data at the node in top.

- void delete_at ( const int& ), removes the node in position from list. 


#### Queue(FIFO) Methods

- void erase (), frees all the memory using by its nodes.

- void print (), prints queue by front to back.

- void push ( const datatype& ), add a new node with 'arg' to queue. 

- void pop (), removes next node from queue.

- void swap ( const int& , const int& ), assign the data in pos1 to pos2, and pos2 to pos1.

- datatype front (), gives the data at the next node.  

- datatype back (), gives the data at the last node.

- void delete_at ( const int& ), removes the node in position from list. 

#### Map Methods

- void erase (), frees all the memory using by its nodes.

- void print (), prints map by keys and values.

- void push ( const string& , const datatype&  ), adds a new key with 'arg' to map. 

- void remove ( const string&  ), removes from the map the node with key.

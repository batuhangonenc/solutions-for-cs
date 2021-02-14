#ifndef STACK_H_
#define STACK_H_

#include <iostream>
#include <stdlib.h>


template <typename datatype>

class stack {
private:
	struct node {
		datatype data;
		node* next;
	};
public:
	node* const root = (node*) malloc ( sizeof ( node ));
	int size = 0;

	stack () {
		root -> data = NULL;
		root -> next = NULL;
	}

	stack ( int len ) {
		root -> data = NULL;
		root -> next = NULL;

		node* iter = root;

		for ( int i{ 0 } ; i < len ; i++){
			iter -> next = (node*) malloc ( sizeof ( node ));
			iter = iter -> next;

			iter -> data = NULL;
			iter -> next = NULL; 
		}
	}

	stack ( datatype* arr, int len ){
		root -> next = NULL;
		root -> data = NULL;

		node* iter = root;

		for( int i { 0 }; i < len ; i++ ){
			iter -> next = (node*) malloc ( sizeof ( node ));
			iter = iter -> next;

			iter -> data = arr[i];
			iter -> next = NULL;
			size++;
		}
	}

	bool is_empty () const {
		if ( root -> next == NULL )
			return true;
		return false;
	}

	void erase () {
		if ( root -> next == NULL )
			return;

		node* target;
		
		for( ;; ) {
			target = root;
			if ( root -> next == NULL ){
				free( target );
				return;
			}

			else {
				root = root -> next;
				free( target );
			}
		}
	}

	void print () const {
		if(root -> next == NULL)
			return;

		node* iter = root -> next; 

		for( int i{0} ; iter != NULL ; i++, iter = iter -> next)
			std :: cout << "node "<<i << " : "<< iter -> data << std :: endl;
		
		std::cout << "	\n\n";
		return;
	}

	datatype top () const {
		return ( datatype )( root -> next -> data );
	}

	void pop () {
		node* target = root -> next;

		root -> next = root -> next -> next;
		free ( target );

		size--;
		return;
	}

	void push ( datatype arg ) {
		
		node* new_node = (node*) malloc ( sizeof ( node ));

		new_node -> next = root -> next ;
		new_node -> data = arg;

		root -> next = new_node;
		
		size++;
		return;
	}

	void swap ( int pos1, int pos2 ) {
		node* iter = root;
		datatype holder_1, holder_2;

		for ( int crr{ -1};; ) {
			if ( crr == pos1 ){ 
				holder_1 = iter -> data;
				
				iter = iter -> next;
				crr++;
			}
			else if ( crr == pos2 ){
				holder_2 = iter -> data;
				iter -> data = holder_1;
				break;
			}

			else {
				iter = iter -> next;
				crr++;
			}
		}
	
		iter = root;
		for ( int crr{ -1};; ) {
			if ( crr == pos1 ) {
				iter -> data = holder_2;
				return;
			}

			else {
				iter = iter -> next;
				crr++;
			}
		}
	}


	
};

#endif

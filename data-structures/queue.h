#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
#include <stdlib.h>

template <typename datatype>
class queue {
private:
	struct node {
		datatype data;
		node* next;
	};
public:
	int size{0};
	node* root = (node*) malloc ( sizeof ( node ));

	queue () {
		root -> next = NULL;
	}

	queue ( datatype* arr, int len ) {

		root -> next = NULL;
		node* iter = root;

		for ( int i{ 0 } ; i < len ; i++){
			iter -> next = (node*) malloc ( sizeof ( node ));
			iter = iter -> next;

			iter -> data = arr[i];
			iter -> next = NULL;
		}
	}

	void erase () {
		node* target;

		for ( ;; ) {
			target = root;
			if ( root -> next == NULL ){
				free ( target );
				return;
			}

			else {
				root = root -> next;
				free ( target );
			}
		}
	}

	void print () const {
		if ( root -> next == NULL )
			return;

		node* iter = root -> next;
		int i { 0} ;

		while ( iter != NULL ){
			std :: cout << "node " << i++ << " : " << iter -> data << "\n";
			iter = iter -> next;
		}

		std :: cout << "\n\n";
		return;
	}

	void swap ( int pos1, int pos2 ) {
		node* iter = root;
		datatype
	 holder_1, holder_2;

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


	datatype front () const {
		return ( datatype )(root -> next -> data);
	}

	datatype back () const {
		node* iter = root;

		while ( iter -> next != NULL )
			iter = iter -> next;

		return ( datatype )( iter -> data );
	}

	void push ( datatype arg ) {
		node* iter = root;

		while ( iter -> next != NULL )
			iter = iter -> next;

		node* new_node = (node*) malloc ( sizeof ( node ));

		new_node -> next = NULL;
		new_node -> data = arg;

		iter -> next  = new_node;
		return;		
	}

	void pop () {
		node* target = root -> next;
		
		root -> next = root -> next -> next;
		
		free ( target );
		return;		
	}

};


#endif

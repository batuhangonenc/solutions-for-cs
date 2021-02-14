#ifndef linkedlist
#define linkedlist

#include <iostream>
#include <stdlib.h>

template <typename datatype>
class LinkedList {
private:
	struct node {
		datatype data;
		node* next;
	};
public:
	node* const root = (node*) malloc ( sizeof(node));

	LinkedList () {
		root->next = NULL;
		root->data = NULL;
	}

	LinkedList ( int len ) {
		root -> data = NULL;
		root -> next = NULL;

		node* iter = root;	

		for(int i{0} ; i < len ; i++){
			iter->next = (node*) malloc ( sizeof(node));

			iter = iter->next;	
			
			iter->data = NULL;
			iter->next = NULL;

		}
	}

	LinkedList( datatype* arr, int SIZE ) {
		root -> data = NULL;
		root -> next == NULL;
		
		node* iter = root;	

		for ( int i{0} ; i < SIZE ; i++ ) {
			iter->next = (node*) malloc ( sizeof(node));

			iter = iter->next;
			
			iter->data = arr[i];
			iter->next = NULL;
		}
	}


	void erase () {
		node* target;

		for(;;){

			target = root;
			if( root -> next == NULL )
			{
				free(target);
				return;
			}

			else
			{
				root = root -> next;
				free(target);
			}
		}
	}

	datatype at ( int pos ) const {
	
		node* iter = root;
		int crr{-1};

		while ( iter->next != NULL && crr != pos ) {
			iter = iter->next;
			crr++;
		}
		
		return iter->data;
	}


	int i{0}; 
	void reverse ( node* iter ) {
		if( iter == NULL )
			return;

		reverse(iter->next);

		std::cout <<"node "<<i++<< " : "<< iter->data << std::endl;

	}
	
	void reverse () {
		if( root  == NULL )
			return;

		reverse(root->next);

		std::cout <<"node "<<i++<< " : "<< root->data << std::endl;

	}

	void print () const {
		if ( root -> next == NULL )
			return;

		node* iter = root -> next; 

		for ( int i{0} ; iter != NULL ; i++, iter = iter -> next)
			std :: cout << "node "<<i << " : "<< iter -> data << std :: endl;
		
		std::cout << "\n\n";
		return;
	}


	void change_at ( datatype arg, int pos ) {
		if(root -> next == NULL)
			return;

		if( arg == NULL )
			return;

		node* iter = root;

		for ( int crr{-1} ; ;){
			if ( iter == NULL ) {
				std::cout << "NULL PTR... GUESS WHY\n";
				break;
			}
		

			else if ( crr == pos ) {
				iter->data = arg;
				break;
			}
			

			else {
				iter = iter->next ;
				crr++;
			}
		}

		return;

	}




	void push_front ( datatype arg ) {
		if (arg == NULL)
		       return;

		node* newnode = (node*) malloc ( sizeof(node));

		newnode->data = arg;
		newnode->next = root->next;

		root->next = newnode;

		return;
	}

	void push_end ( datatype arg ) {
		if( arg == NULL )
			return;

		node* iter = root;
		node* new_node = (node*) malloc ( sizeof(node));

		new_node -> next = NULL;
		new_node -> data = arg;

		for (; iter->next != NULL ;)
			iter = iter->next;

		iter -> next = new_node;
	}


	void delete_at( int pos ) {
		if(root -> next == NULL)
			return;


		node* iter = root;

		for(int crr{-1}; iter != NULL ;){

			if ( crr == pos - 1){
				node* del = iter -> next;

				iter -> next = iter -> next -> next;
				free(del);

				return;
			}

			else{
				iter = iter->next;
				crr++;
			}
		}


		std::cout << "\n\nNULLPTR\n\n";
	}


	void concat ( node* new_root ) {
		if ( new_root -> next == NULL)
			return;

		node* iter = root;

		for (; iter->next != NULL ;)
			iter = iter->next;

		iter -> next = new_root -> next;
		return;
	}

	void insert ( node* new_root, int pos ) {
		if ( new_root -> next == NULL || root -> next == NULL )
			return;

		node* iter = root;
		for ( int crr{-1} ; ;){

			if ( crr == pos - 1) {
				new_root = new_root->next;
				
				node* b_iter = iter->next;

				iter->next = new_root;

				while ( new_root->next != NULL ){
					new_root = new_root->next;
				}

				new_root -> next = b_iter;
				return;

			}

			else if ( iter->next == NULL) {
				concat(new_root);
				return;
			}


			else {
				iter = iter->next;
				crr++;
			}
		}
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

#ifndef linkedlist
#define linkedlist

#include <iostream>
#include <stdlib.h>

template <typename datatype>
class LinkedList {
private:
	bool erase_called = false;

	struct node {
		datatype data;
		node* next;
	};
public:
	node* root = new node;

	LinkedList () {
		root->next = nullptr;
		root->data = NULL;
	}

	LinkedList ( const int& len ) {
		root -> next = nullptr;

		node* iter = root;	

		for(int i{0} ; i < len ; i++){
			iter->next = new node;

			iter = iter->next;	
			
			iter->next = nullptr;

		}
	}

	LinkedList( const datatype* arr, const int& SIZE ) {
		root -> next == nullptr;
		
		node* iter = root;	

		for ( int i{0} ; i < SIZE ; i++ ) {
			iter->next = new node;

			iter = iter->next;
			
			iter->data = arr[i];
			iter->next = nullptr;
		}
	}

	LinkedList( const LinkedList& ll ) {
		if ( ll.root == NULL || ll.root -> next == NULL )
			return;

		node* iter_ll = ll.root;
		int llsize = 0;
		while ( iter_ll -> next != NULL ) {
			iter_ll = iter_ll -> next;
			++llsize;
		}

		node* iter = root;
		for ( int i{-1} ; i < llsize ; ++i ) {	
			iter -> next = new node;

			iter = iter -> next;
			iter -> data = ll.at(i);
			iter -> next = nullptr;
		}	
	}

	LinkedList( LinkedList&& ll ) {
		if ( ll.root == NULL || ll.root -> next == NULL )
			return;

		node* iter_ll = ll.root;
		int llsize = 0;
		while ( iter_ll -> next != NULL ) {
			iter_ll = iter_ll -> next;
			++llsize;
		}


		node* iter = root;
		for ( int i{-1} ; i < llsize ; ++i ) {	
			iter -> next = new node;

			iter = iter -> next;
			iter -> data = ll.at(i);
			iter -> next = nullptr;
		}	

	}

	void erase () {
		node* target;

		for(;;){

			target = root;
			if( root -> next == nullptr )
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

	// operator overloading

	void operator=( LinkedList&& ll ) {
		erase();
		erase_called = false;

		node* iter_ll = ll.root;
		int llsize = 0;
		while ( iter_ll -> next != NULL ) {
			iter_ll = iter_ll -> next;
			++llsize;
		}


		node* iter = root;
		for ( int i{-1} ; i < llsize ; ++i ) {	
			iter -> next = new node;

			iter = iter -> next;
			iter -> data = ll.at(i);
			iter -> next = nullptr;
		}	
	}

	void operator=(const LinkedList& ll ) {
		erase();
		erase_called = false;


		node* iter_ll = ll.root;
		int llsize = 0;
		while ( iter_ll -> next != NULL ) {
			iter_ll = iter_ll -> next;
			++llsize;
		}


		node* iter = root;
		for ( int i{-1} ; i < llsize ; ++i ) {	
			iter -> next = new node;

			iter = iter -> next;
			iter -> data = ll.at(i);
			iter -> next = nullptr;
		}	
	}

	datatype operator[]( const int& i ) const {
		return (datatype) at( i );
	}

	datatype operator[]( int&& i ) const {
		return (datatype) at( i );
	}
	//----
	~LinkedList() {
		if (!erase_called)
			erase();
	}

	
	datatype at ( const int& pos ) const {
	
		node* iter = root;
		int crr{-1};

		while ( iter->next != nullptr && crr != pos ) {
			iter = iter->next;
			crr++;
		}
		
		return iter->data;
	}


	int i{0}; 
	void reverse ( node* iter ) {
		if( iter == nullptr )
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


	void print() const {
		if ( root -> next == nullptr )
			return;

		node* iter = root -> next; 

		for ( int i{0} ; iter != nullptr ; i++, iter = iter -> next)
			std :: cout << "node "<<i << " : "<< iter -> data << std :: endl;
		
		std::cout << "\n\n";
		return;
	}



	void change_at( const datatype& arg, const int& pos ) const {
		if(root -> next == nullptr)
			return;

		if( arg == NULL )
			return;

		node* iter = root;

		for ( int crr{-1} ; ;){
			if ( iter == nullptr ) {
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




	void push_front ( const datatype& arg ) {
		if (arg == NULL)
		       return;

		node* newnode = new node;

		newnode->data = arg;
		newnode->next = root->next;

		root->next = newnode;

		return;
	}

	void push_end ( const datatype& arg ) {
		if( arg == NULL )
			return;

		node* iter = root;
		node* new_node = new node;

		new_node -> next = nullptr;
		new_node -> data = arg;

		for (; iter->next != nullptr ;)
			iter = iter->next;

		iter -> next = new_node;
	}


	void delete_at( const int& pos ) {
		if(root -> next == nullptr)
			return;


		node* iter = root;

		for(int crr{-1}; iter != nullptr ;){

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


	void concat ( const node* new_root ) const {
		if ( new_root -> next == nullptr)
			return;

		node* iter = root;

		for (; iter->next != nullptr ;)
			iter = iter->next;

		iter -> next = new_root -> next;
		return;
	}

	void insert ( const node* new_root, const int& pos ) const {
		if ( new_root -> next == nullptr || root -> next == nullptr )
			return;

		node* iter = root;
		for ( int crr{-1} ; ;){

			if ( crr == pos - 1) {
				new_root = new_root->next;
				
				node* b_iter = iter->next;

				iter->next = new_root;

				while ( new_root->next != nullptr ){
					new_root = new_root->next;
				}

				new_root -> next = b_iter;
				return;

			}

			else if ( iter->next == nullptr ) {
				concat(new_root);
				return;
			}


			else {
				iter = iter->next;
				crr++;
			}
		}
	}

	void swap ( const int& pos1, const int& pos2 ) const {
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

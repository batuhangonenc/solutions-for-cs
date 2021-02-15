#ifndef STACK_H_
#define STACK_H_

#include <iostream>

template <typename datatype>

class stack {
private:
	bool erase_called = false;
	struct node {
		datatype data;
		node* next;
	};

public:

	node* root = new node;

	int size = 0;

	stack () {
		root -> next = nullptr;
	}

	stack ( const int& len ) {
		root -> next = nullptr;

		node* iter = root;

		for ( int i{ 0 } ; i < len ; i++){
			iter -> next = new node;
			iter = iter -> next;

			iter -> data = NULL;
			iter -> next = nullptr; 
		}

		size = len;
	}

	stack ( const datatype* arr, const int& len ){
		root -> next = nullptr;

		node* iter = root;

		for( int i { 0 }; i < len ; i++ ){
			iter -> next = new node;
			iter = iter -> next;

			iter -> data = arr[i];
			iter -> next = nullptr;
			++size;
		}
	}


	void erase () {
		if ( root -> next == nullptr )
			return;

		node* target;
		
		for( ;; ) {
			target = root;
			if ( root -> next == nullptr ){
				delete target;
				return;
			}

			else {
				root = root -> next;
				delete target;
			}
		}
		erase_called = true;
	}

	~stack() {
		if(!erase_called)
			erase();
	}

	stack ( const stack& s ) {
		node* iter = root;
		for ( int i{0} ; i < s.size ; ++i ) {
			iter -> next = new node;

			iter = iter -> next;
			iter -> data = s.at(i);
			iter -> next = nullptr;
		}	
		size = s.size;
	}

	stack ( const stack&& s ) {
		node* iter = root;
		for ( int i{0} ; i < s.size ; ++i ) {
			iter -> next = new node;

			iter = iter -> next;
			iter -> data = s.at(i);
			iter -> next = nullptr;
		}	
		size = s.size;
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

				--size;
				return;
			}

			else{
				iter = iter->next;
				crr++;
			}
		}


		std::cout << "\n\nNULLPTR\n\n";
	}

	void operator=( const stack& s ) {
		erase();
		erase_called = false;

		node* iter = root;
		for ( int i{0} ; i < s.size ; ++i ) {
			iter -> next = new node;

			iter = iter -> next;
			iter -> data = s.at(i);
			iter -> next = nullptr;
		}	
		size = s.size;
	}

	void operator=( const stack&& s ) {
		erase();
		erase_called = false;

		root = s.root;
		size = s.size;
	}

	datatype operator[]( const int& i ) const {
		return (datatype) at( i );
	}

	datatype operator[]( int&& i ) const {
		return (datatype) at( i );
	}

	bool is_empty () const {
		if ( root -> next == nullptr )
			return true;
		return false;
	}

	datatype at( const int& pos ) const {
		node* iter = root;

		int crr{ -1 };
		while ( iter->next != NULL && crr != pos )
		{
			iter = iter -> next;
			++crr;
		}	

		return iter->data;
	}


	void print () const {
		if(root -> next == nullptr)
			return;

		node* iter = root -> next; 

		for( int i{0} ; iter != nullptr ; i++, iter = iter -> next)
			std :: cout << "node "<<i << " : "<< iter -> data << std :: endl;
		
		std::cout << "	\n\n";
		return;
	}

	datatype top () const {
		if ( root == NULL || root -> next == NULL )
			return NULL;

		return ( datatype )( root -> next -> data );
	}

	void pop () {
		node* target = root -> next;

		root -> next = root -> next -> next;
		delete target ;

		--size;
		return;
	}

	void push ( const datatype& arg ) {
		
		node* new_node = new node;

		new_node -> next = root -> next ;
		new_node -> data = arg;

		root -> next = new_node;
		
		++size;
		return;
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

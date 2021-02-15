#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>

template <typename datatype>
class queue {
private:
	bool erase_called = false;
	struct node {
		datatype data;
		node* next;
	};
public:
	int size{0};
	node* root = new node;

	queue () {
		root -> next = nullptr;
	}

	queue ( const datatype* arr, int len ) {

		root -> next = nullptr;
		node* iter = root;

		for ( int i{ 0 } ; i < len ; i++){
			iter -> next = new node;
			iter = iter -> next;

			iter -> data = arr[i];
			iter -> next = nullptr;
		}

		size = len;
	}

	void erase () {
		if ( root == NULL || root -> next == NULL )
			return;

		node* target;

		for ( ;; ) {
			target = root;
			if ( root -> next == NULL ){
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

	queue ( const queue& q ) {
		if ( q.root == NULL || q.root -> next == NULL ) {
			queue();
			return;
		}

		node* iter = root;
		for ( int i{0} ; i < q.size ; ++i ) {
			iter -> next = new node;

			iter = iter -> next;
			iter -> data = q.at(i);
			iter -> next = nullptr;
		}	
		size = q.size;
	}

	queue ( const queue&& q ) {
		root = q.root;
		size = q.size;
	}

	~queue() {
		if ( !erase_called )
			erase();
	}
	

	void operator=( const queue& q ) {
		erase();
		erase_called = false;

		node* iter = root;
		for ( int i{0} ; i < q.size ; ++i ) {
			iter -> next = new node;

			iter = iter -> next;
			iter -> data = q.at(i);
			iter -> next = nullptr;
		}	
		size = q.size;
	}


	void operator=( const queue&& q ) {
		erase();
		erase_called = false;

		root = q.root;
		size = q.size;
	}

	datatype operator[]( const int& i ) const {
		return (datatype) at( i );
	}

	datatype operator[]( int&& i ) const {
		return (datatype) at( i );
	}


	void print () {
		if ( root -> next == nullptr )
			return;

		node* iter = root -> next;
		int i { 0} ;

		while ( iter != nullptr ){
			std :: cout << "node " << i++ << " : " << iter -> data << "\n";
			iter = iter -> next;
		}

		std :: cout << "\n\n";
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

	datatype front() const {
		return ( datatype )(root -> next -> data);
	}

	datatype back() const {
		if ( root == NULL || root -> next == NULL )
			return NULL;

		node* iter = root;
		while ( iter -> next != NULL )
			iter = iter -> next;

		return iter -> data;
	}

	
	void push( datatype arg ) {
		if ( root-> next == nullptr )
			return;

		node* iter = root;
		while ( iter -> next != nullptr )
			iter = iter -> next;


		node* newnode = new node;

		newnode->next = root->next;
		newnode->data = arg;

		iter->next = newnode;
		return;
	}

	datatype at( int pos ) const {
		if ( root == NULL || root->next == NULL)
			return node().data;

		node* iter =root;

		int crr{-1};
		while ( iter->next != nullptr && crr != pos ) {
			iter = iter->next;
			crr++;
		}

		return iter -> data;
	}

	void pop () {
		node* target = root -> next;
		
		root -> next = root -> next -> next;
		
		free ( target );
		return;		

	}

};


#endif

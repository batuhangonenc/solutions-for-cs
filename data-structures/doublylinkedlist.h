#include <iostream>

#ifndef doublylinkedlist
#define doublylinkedlist

template <typename datatype>
struct DoublyLinkedList{

	struct node {
		datatype data;
		node* next;
		node* prev;
	};

	node* root = new node;
	
	DoublyLinkedList(){
		root -> next = NULL;
		root -> prev = nullptr;
	}

	DoublyLinkedList(int len){
		root -> prev = nullptr;
		root -> data = NULL;
		root -> next = NULL;

		node* iter = root;	

		for(int i{0} ; i < len ; i++){
			iter->next = new node;

			iter->next->prev = iter;
			iter = iter->next;	
			
			iter->data = NULL;
			iter->next = NULL;

		}
	}


	DoublyLinkedList(datatype* arr, int SIZE){

		root -> prev = nullptr;
		root -> data = NULL;
		root -> next = NULL;


		node* iter = root;	
	
		for(int i{0} ; i < SIZE ; i++){
			iter->next = new node;

			iter->next->prev = iter;
			iter = iter->next;
			
			iter->data = arr[i];
			iter->next = NULL;

		}
	}

	void self_destruct(){
		if ( root -> next == NULL )
			return;

		while(true){
			node* iter_deleter = root;

			iter_deleter -> data = NULL;
			iter_deleter -> prev = nullptr;
			iter_deleter -> next = nullptr;

			if( root -> next  == NULL )
				break;

			root = root -> next;
		}

	}


	datatype at(int pos){
		if(root -> next == NULL)
			return;

		node* iter = root;

		int i{0};
		while(iter->next != NULL && i != pos + 1){
			iter = iter->next;
			i++;
		}
		
		return iter->data;
	}

	int i{0};
	void reverse(node* iter){
		if( iter == NULL )
			return;

		reverse(iter->next);

		std::cout << "node " <<i++ << " : "<< iter->data << "\n";

	}
	
	void reverse(){
		if( root == NULL )
			return;

		reverse(root->next);

		std::cout << "node " <<i++ << " : "<< root->data << "\n";

	}

	void print(){
		if(root -> next == NULL)
			return;

		node* iter = root;

		for(int i{0} ; ; i++){
			if ( iter -> next == NULL )
				return;

			iter = iter->next ;
			std::cout << "node " << i << " :"<< iter->data << "\n";
		}
		std::cout << "\n\n\n";
		return;
	}


	void change_at(int pos, datatype arg){
		if( arg == NULL || root -> next == NULL)
			return;
		
		node* iter = root;

		for(int i{0} ; ;){
			if(iter == NULL){
				std::cout << "NULL PTR... GUESS WHY\n";
				break;
			}
			

			else if( i - 1 == pos){
				iter->data = arg;
				break;
			}
			

			else{
				iter = iter->next ;
				i++;
			}
		}

		return;

	}


	void push_front(datatype arg){
		if( arg == NULL )
			return;

		node* newnode = new node;

		newnode->data = arg;
		newnode->prev = root;
		newnode->next = root->next;

		root->next = newnode;

		return;
	}

	void push_end(datatype arg){
		if ( arg == NULL )
		       return;	

		node* iter = root;

		for(; iter->next != NULL ;)
			iter = iter->next;

		iter->next = new node;

		iter->next->prev = iter;
		iter = iter->next;
		
		iter->data = arg;
		iter->next = NULL;
	}


	void delete_at( int pos){
		if(root -> next == NULL)
			return;

		node* iter = root;

		for(int i{0}; iter != NULL ;){

			if ( i == pos ){
				node* deleted = new node;
				deleted = iter->next;

				iter->next->next->prev = iter;
				iter -> next =iter->next->next;

				delete deleted;
				return;
			}

			else{
				iter = iter->next;
				i++;
			}
		}


		std::cout << "\n\nNULLPTR\n\n";
	}


	void concat(node* new_root){
		if ( new_root -> next == NULL)
			return;

		node* iter = root;

		for(; iter->next != NULL ;)
			iter = iter->next;

		new_root->next->prev = iter;

		iter->next = new_root->next;
		return;
	}

	void insert(int pos, node* new_root){
		if( root -> next == NULL || new_root -> next == NULL)
			return;
		
		node* iter = root;
		for(int i{0} ; ;){

			if( i  == pos ){
				new_root = new_root->next;

				node* b_iter = iter->next;

				new_root -> prev = iter;
				iter->next = new_root;

				while( new_root->next != NULL ){
					new_root = new_root ->next;
				}

				b_iter->prev = new_root;
				new_root ->next = b_iter;
				return;

			}

			else if( iter->next == NULL){
				concat(new_root);
				return;
			}


			else{
				iter = iter->next;
				i++;
			}
		}
	}
};
#endif

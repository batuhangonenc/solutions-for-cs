#ifndef circularlinkedlist
#define circularlinkedlist

#include<iostream>
#include<stdlib.h>

template <typename datatype>
struct CircularLinkedList{

	struct node {
		datatype data;
		node* next;
	};

	node* head = new node;

	
	CircularLinkedList(){
	
	head->data = NULL;
	head->next = NULL;

	}

	void erase(){
		if ( head -> next == NULL )
			return;

		node* start_point = head ;

		head = head -> next;

		node* target;

		for(;;){

			target = head;
			if( target -> next == start_point )
			{
				free(target);
				return;
			}

			else
			{
				head = head -> next;
				free(target);
			}
		}
	}

	void print(){
		int i{0};

		if( head->next == NULL )
			return;

		head = head -> next;
		
		while( head -> data != NULL){
		std::cout << "node "<<i++<<" : "<< head->data << "\n";
		head = head->next;
		}
		
		std::cout << "\n\n";
		
	 }
	
	void push( datatype arg ){
	
		if( arg == NULL){
			return;
		}

		else if( head->next == NULL){
			node* new_node = new node;

			new_node -> data = arg;
			new_node -> next = head;

			head -> next = new_node;
		}

		else {

			node* iter = head;

			while( iter->next->data != NULL )
				iter = iter->next;
			
			node* new_node = new node;

			new_node -> data = arg;
			new_node -> next = head;

			iter -> next = new_node;
	
		}	
	}

	void delete_at(int pos){
		if(head->next == NULL)
			return;

		node* iter = head -> next;
		for(int crr{ -1 } ;; ){
			
			if ( iter == head )
				return;

			else if( crr == pos ){
				node* del = iter -> next;

				iter -> next = iter -> next -> next;
				free(del);
				return;
			}

			else
			{
				iter = iter->next;
				crr++;
			} 	
		}
	}

	void insert(int pos, node* new_head){
		if( head->next == NULL && new_head -> next != NULL ){
			head -> next = new_head -> next ;
			return;
		}

		else if( head->next == NULL && new_head -> next == NULL )
			return;

		else if( new_head -> next == NULL )
			return;


		node* iter = head;
		
		int i{0};
		while( iter->next->next->data != NULL && i != pos ){
			iter = iter -> next ;
			i++;
		}
		
		node* b_iter = iter->next;

		iter -> next = new_head -> next ;


		while( new_head->next->data != NULL ){
			new_head = new_head -> next ;
			i++;
		}

		new_head -> next = b_iter ;

	}	
};

#endif

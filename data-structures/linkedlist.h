#include<iostream>

#ifndef linkedlist
#define linkedlist

template <typename datatype>
struct LinkedList{

	struct node {
		datatype data;
		node* next;
	};

	node* root = new node;

	LinkedList(){
		node* iter = root;
		iter->next = NULL;
	}

	LinkedList(int len){
		node* iter = root;	

		for(int i{0} ; i < len ; i++){
			iter->next = new node;

			iter = iter->next;	
			
			iter->data = NULL;
			iter->next = NULL;

		}
	}

	LinkedList(datatype* arr, int SIZE){
		node* iter = root;	

		for(int i{0} ; i < SIZE ; i++){
			iter->next = new node;

			iter = iter->next;
			
			iter->data = arr[i];
			iter->next = NULL;

		}
	}


	datatype at(int pos){
	
		node* iter = root;

		int i{0};
		while(iter->next != NULL && i != pos + 1){
			iter = iter->next;
			i++;
		}
		
		return iter->data;
	}


	int i{0};
	void rprint(node* root){
		if( root == NULL )
			return;

		rprint(root->next);

		std::cout <<"node "<<i++<< " : "<< root->data << std::endl;

	}

	void print(){

		node* iter = root;

		for(int i{0} ; iter->next != NULL ; i++){
			iter = iter->next ;
			std::cout << "node " << i << " :"<< iter->data << "\n";
		}
		std::cout << "\n\n\n";
		return;
	}


	void change(int pos, datatype arg){
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




	void push_front(datatype n){
		node* newnode = new node;

		newnode->data = n;
		newnode->next = root->next;

		root->next = newnode;

		return;
	}

	void push_end(datatype n){
		node* iter = root;

		for(; iter->next != NULL ;)
			iter = iter->next;

		iter->next = new node;

		iter = iter->next;
		
		iter->data = n;
		iter->next = NULL;
	}


	void deleteit( int pos){
		node* iter = root;

		for(int i{0}; iter != NULL ;){

			if ( i == pos ){
				node* deleted = new node;
				deleted = iter->next;

				iter->next = iter->next->next;

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


	void concat(node* r2){
		node* iter = root;

		for(; iter->next != NULL ;)
			iter = iter->next;

		iter->next = r2->next;
		return;
	}

	void insert(int pos, node* nr){
		node* iter = root;
		for(int i{0} ; ;){

			if( i  == pos ){
				nr = nr->next;
				
				node* b_iter = iter->next;

				iter->next = nr;

				while( nr->next != NULL ){
					nr = nr->next;
				}

				nr->next = b_iter;
				return;

			}

			else if( iter->next == NULL){
				concat(nr);
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

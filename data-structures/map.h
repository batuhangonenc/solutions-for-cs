#ifndef MAP_H_
#define MAP_H_

#include <iostream>
#include "queue.h"

using std::cout;
using std::endl;
using std::string;

template <typename datatype>
class map
{
private:
	queue<string> keys;

	bool erase_called = false;

	struct map_node {
		string key;
		datatype data;
		map_node* next;
	};

public:
	map_node* root = new map_node;

	map() {
		root -> key = "root";
		root -> next = NULL;

		keys.push("root");
	}

	map( const map& m ) {
		map_node* iter = root;
		map_node* iter2 = m.root;
		
		for( int i{0} ; i < m.GetSize() ;++i)
		{
			iter = iter -> next;
			iter2 = iter2 -> next;

			iter -> key = iter2 -> key;
			keys.push(iter->key);

			iter -> data  = iter2 ->data;
			iter -> next = iter2 -> next;
		}	
	}


	bool is_str_eq( const string& s1, const string& s2 ) const {
		char a, b;
		for( int i{0} ; i < s1.size() && i < s2.size() ; ++i ) {
			a = (char)s1[i];
			b = (char)s2[i];

			if( !( a == b ) )
				return false;
		}
		return true;
	}

	datatype& operator[]( const string& s ) const {
		if( root == NULL || root-> next == NULL )
			return root->data;

		map_node* iter = root;
		for(;;) {
			if ( iter -> next == NULL )
				return iter->data;

			else if( is_str_eq( iter->key, s) )
				return iter->data;

			else
				iter = iter ->next;
		}
	}	

	datatype& operator[]( const int& i ) const {
		if( root == NULL || root-> next == NULL )
			return root->data;

		map_node* iter = root;
		for(int crr{-1} ;;) {
			if ( iter -> next == NULL )
				return iter->data;

			else if (crr == i )
				return iter->data;

			else {
				iter = iter ->next;
				++crr;	
			}
		}
	}	

	void print() const {
		int i{0};
		while( i < keys.size-1 ) {
			cout << "key : " << keys[i+1]<< " value : " << this->at(i) << endl;
			++i;
		}
		cout << "\n\n";
	}

	void push( const string& k, const datatype& data ) {
		map_node* newNode = new map_node;

		for(int i{0} ; i < keys.size ; ++i )
			if ( is_str_eq( keys.at(i) , k) )
				return;


		keys.push(k);		

		newNode -> key = k;
		newNode -> data = data;
			
		if( root->next == NULL ) {
			root -> next = newNode;
			newNode -> next = NULL;
			return;

		} else {

			map_node* iter = root;
			while( iter -> next != NULL )
				iter = iter -> next;

			iter -> next = newNode;
			newNode -> next = nullptr;

			return;
		}
	}


	void remove( const string& key ){
		if( root == NULL || root-> next == NULL )
			return ;

		map_node* iter = root;
		for(int crr{-1} ;;) {
			if ( iter -> next == NULL )
				return ;

			else if ( is_str_eq(key, iter -> next -> key)  )
			{
				map_node* d = iter -> next;
				iter -> next = iter -> next -> next;


				keys.delete_at(crr+2);
				delete d;
			}

			else {
				iter = iter ->next;
				++crr;	
			}
		}
	}

	void erase () {
		map_node* target;

		for(;;){

			target = root;
			if( root -> next == nullptr )
			{
				delete target;
				return;
			}

			else
			{
				root = root -> next;
				delete target;
			}
		}
		erase_called = true;
	}

	~map() {
		if( !erase_called )
			erase();
	}


	int GetSize() const {
		return keys.size;
	}

	queue<string> GetKeys() const {
		return (queue<string>)( keys );
	}

	datatype at( const int& pos ) const {
		map_node* iter = root;
		for(int crr{-1} ; ; )
		{
			if( iter -> next == NULL || crr == pos )
				return iter ->data;
			iter = iter -> next;
			++crr;
		}
	}
};

#endif

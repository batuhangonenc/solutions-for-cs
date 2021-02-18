#ifndef GINT_H_
#define GINT_H_

#include <cstring>

class gint
{
private:
	int SIZE {1};
	char* data { new char[SIZE] };

public:
	gint() {}

	gint( const int& S, const char& ch ) {
		SIZE = S;
		data = new char[SIZE];
		memset( data, ch, SIZE);
	}

	~gint() {
		delete[] data;
	}

	void erase() {
		delete[] data;
		SIZE = 0;
	}

	char* get_data() const {
		return data;
	}

	int get_size() const {
		return SIZE;
	}

	void set_size( const int& S ) {
		memset( data, 0, SIZE);
		SIZE = S;
	}
	
	char& operator[]( const int& i ) {
		return data[i];
	}

	void operator=( gint& g ) {
		set_size( g.get_size() );
		
		for( int i{0} ; i < SIZE ; ++i ) 
			memset( data + i, g[i], 1);
	}

	char* rparse_int( const long int& arg ) const {
		int tempsize{ 1 };
		long int holder{ arg };

		for( ;; ) {
			if (holder < 10)
				break;

			holder /= 10;
			++tempsize;
		}

		holder = arg;

		char* tmp{ new char[ tempsize ] };
			
		for( int i{ -1 } ;; ) {
			if (holder < 10) {
				memset( tmp + (++i), holder + 48, 1);
				break;
			}

			memset( tmp + (++i), (holder % 10) + 48, 1);
			holder /= 10;
		}

		return (char*)tmp;
	}

	char* reverse_sort( const char* arg ) {
		int s{0};
		while ( arg[s] != '\0')
			++s;

		char* newstr { new char[s] };

		for( int i {0} ; i < s ; ++i) 
			memset( newstr + i, arg[ s - i - 1 ] , 1);

		std:: cout << "\n(reverse sort)\narg : " << arg << "\nsize : "<< s << "\nreversed : " << newstr << "\n\n";

		return newstr;

	}


	void add( const long int& arg ) {
		int TEMP = 0;
		char* __TEMP__ = rparse_int(arg);
		while( __TEMP__[ TEMP ] != '\0' )
			++(TEMP);

		std::cout <<"adding : " << arg << "\n";

		data = reverse_sort( data );

		if ( arg >= 0 && arg <= 9 ){
			if( arg + data[0] > 57 ) {
				memset( data , data[1] + arg - 10, 1);
				
				int i{1}, sflag{0};
				while ( data[i] == 57) {
					if( i == SIZE - 1 ) {
						sflag = 1;
						break;
					}

					memset( data + i, 48, 1);
					++i;
				}

				if (sflag == 1) {
					++SIZE;
					memset( data + i, 49, 1);
				}

				else 
					memset( data + i, data[i] + 1, 1);
				

				data = reverse_sort(data);
				return;
			}	

			else {
				memset( data, arg + data[0], 1);
				data = reverse_sort( data );
				return;
			}

		}
		

		else if ( TEMP > SIZE) {
			std:: cout << "data : " << data << " size : " << SIZE << "\n";

			int ndsize = SIZE;
			SIZE = TEMP;
			char* nd = data;
			data = __TEMP__;


			std:: cout << "data : " << data << " size : " << SIZE << "\n";


			for( int i{0}, a{-1}, b{-1} ; i < ndsize && i < SIZE; ++i ) {
				
				a = data[i] - 48, b = nd[i] - 48;
				
				if( a + b >= 10 ) {
					memset( data + i, a + b - 10 + 48, 1);

					for( int ct{1} ;; ) {
						
						if ( ct == SIZE - 1 && data[ i + ct ] == 57 ) {
							memset( data + i + ct, 48, 1);
							++SIZE;
							memset( data + SIZE - 1, 49, 1);
							break;
						}

						else if ( data[ i + ct ] + 1  <= 57 ) {
							memset( data + i + ct, data[i + ct] + 1, 1);
							break;
						}

						memset( data + i + ct, 48, 1);
						++ct;
					}
				}

				else {
					memset( data + i, a + b + 48, 1);
				}	

			}
			
			data = reverse_sort(data);
		}
			

		else {
			int size_sarg{0};
			char* sarg = rparse_int( arg );
			
			while( sarg[size_sarg] != '\0')
				++size_sarg;

			for( int i{0}, a{-1}, b{-1} ; i < size_sarg && i < SIZE; ++i ) {
				
				a = data[i] - 48, b = sarg[i] - 48;
				
				if( a + b >= 10 ) {
					memset( data + i, a + b - 10 + 48, 1);

					for( int ct{1} ;; ) {
						
						if ( ct == SIZE - 1 && data[ i + ct ] == 57 ) {
							memset( data + i + ct, 48, 1);
							++SIZE;
							memset( data + SIZE - 1, 49, 1);
							break;
						}

						else if ( data[ i + ct ] + 1  <= 57 ) {
							memset( data + i + ct, data[i + ct] + 1, 1);
							break;
						}

						memset( data + i + ct, 48, 1);
						++ct;
					}
				}

				else {
					memset( data + i, a + b + 48, 1);
				}	

			}
			
			data = reverse_sort(data);
		}


	}


	
};

#endif

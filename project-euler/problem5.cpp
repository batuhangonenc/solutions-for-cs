//libs
#include <iostream>

//namespace
using namespace std;

long int get_prime_greater_than_n(long int given){long int prime = given + 1;long int n = prime - 1;if (prime == 2 || prime <= 1)return 2;for(;;){if( prime % n == 0 ){prime++;n = prime - 1;continue;}else if( prime % n != 0 && n == 2 ){return prime;}else if( prime % n != 0){n--;}}}

bool test(long long int* given){

	long long int tester = *given;
	
	for(int i{2} ; i <= 20; i++){
		if( tester % i == 0 && i == 20)
			return true;

		else if(tester % i == 0)
			continue;

		else
			return false;
	}

	return false;
	
}

int main()
{
	cout << boolalpha;

	long long int n = 1;

	int primer = 2;

	while(primer <= 20 ){
		n *= primer;
		cout << primer << " - "<< n <<endl;
		primer = get_prime_greater_than_n(primer);
	}

	
	while(!test(&n)){n++;}

	cout << "\n\n" << n << " - "<< test(&n) << "\n\n";



	return 0;
}
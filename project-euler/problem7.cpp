//libs
#include <iostream>

//namespace
using namespace std;

bool is_prime(int &n){
	int num{n}, tester{n-1};

	for(;;){

		if( tester == 2 && num % tester != 0){
			return true;
		}

		else if(num % tester != 0){
			tester--;
			continue;
		}

		else
			return false;
	}
}

int nth_prime(int &n){
	
	int returner{2};
	int nth = n;
	int temp{2}, counter{1};

	while(counter != nth){

		if(is_prime(temp)){
			returner = temp;
			counter++, temp++;
		}

		else
			temp++;

	}

	return returner;

}

int main()
{

cout << "\n\nfind nth prime : ";
int n;cin >> n;

cout <<"\n\n"<< nth_prime(n) << endl;

	
return 0;
}

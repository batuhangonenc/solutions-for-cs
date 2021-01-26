//libs
#include <iostream>

//namespace
using namespace std;

int main()
{


	long long int sum_of_square{0}, square_of_sum{0}, n{0}, temp{0};

	while(n <= 100)
	{
		sum_of_square += ( n * n );

		temp += n;
		n++;
	}

	square_of_sum = temp * temp;


	cout << "\n\nresult is : " <<  square_of_sum  - sum_of_square << endl ;

return 0;
}

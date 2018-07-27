#include <iostream> 
#include <vector>


using namespace std;

int main()
{
	long long a = 600851475143;
	long long b = 2, c = 1;
	
	while (a != 1)
	{
		if (a % b == 0)
		{
			if (b > c)
				c = b;

			a /= b;
			b = 2;
		}
		else
			b++;
	}

	cout << c << "\n";

	return 0;
}
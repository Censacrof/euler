#include <iostream>
#include <vector>

#define LIMIT 10001

using namespace std;

int main()
{
	vector<int> primes;
	primes.push_back(2);

	for (int i = 3; primes.size() < LIMIT; i += 2)
	{
		bool prime = true;
		for (int j = 0; j < primes.size(); j++)
		{
			//cout << i << "\n";
			if (i % primes[j] == 0)
			{
				prime = false;
				break;
			}
		}

		if (prime)
			primes.push_back(i);
	}

	cout << primes.back() << "\n"; 

	return 0;
}
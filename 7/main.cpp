#include <iostream>
#include <vector>

#define LIMIT 500000

using namespace std;

int main()
{
	vector<int> primes;
	primes.reserve(LIMIT);
	primes.push_back(2);
	int pc = 0;

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
		{
			primes.push_back(i);
			int npc = primes.size() * 100 / LIMIT;
			if (npc > pc)
			{
				pc = npc;
				cout << primes.size() * 100 / LIMIT << "%\n";
			}
			
		}
			
	}

	cout << primes.back() << "\n"; 

	return 0;
}

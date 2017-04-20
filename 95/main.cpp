#include <iostream>
#include <math.h>
#include <vector>

#define MAX_X 1000000

typedef long long unsigned int myint;

using namespace std;

myint getDivisorsSum(myint x)
{
	myint n = sqrt(x);
	myint s = 1;
	
	//cout << "(1 " << x << ") "	;
	for (myint i = 2; i < n; i++)
	{
		if (x % i == 0)
		{
			myint d = x / i;
			//cout << "(" << i << " " << d << ") ";
			s += i + d;
		}
	}

	//cout << "\n";

	return s;
}

bool cache[MAX_X];
myint testChain(myint x, int &low)
{
	if (x > MAX_X)
		return 0;

	myint oldx = x;
	myint n = 0;
	vector<myint> v;

	while (1)
	{
		x = getDivisorsSum(x);
		n++;

		if (x == 1 || x > MAX_X) 
		{
			for (int i = 0; i < v.size(); i++)
				cache[v[i]] = true;

			return 0;
		}
		
		if (x < low) low = x;
		if (x == oldx) break;
		if (cache[x] == true) return 0;

		//cout << x << "\n";

		for (int i = 0; i < v.size(); i++)
			if (x == v[i])
				return 0;

		v.push_back(x);	
	}

	for (int i = 0; i < v.size(); i++)
		cache[v[i]] = true;

	return n;
}

int main()
{
	cout << "initiating cache...";
	for (int i = 0; i < MAX_X; i++)
	{
		cache[i] = false;
	} cout << "done\n";

	int max = 0, lowest;
	for (int i = 2; i < MAX_X; i++)
	{
		//cout << "#" << i << "\n";

		int low = MAX_X;
		int x = testChain(i, low);
		if (x > max)
		{
			max = x;
			lowest = low;
		}

		/*if (x != 0)
			cout << "#" << i << " -> " << x << "\n";*/
	}

	cout << "\n\n" << lowest << "\n";

	return 0;
}
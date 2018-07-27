#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#define MAX 999

using namespace std;

bool isPalindrome(int n)
{
	stringstream ss; ss << n;
	string s; ss >> s;

	int j = s.size() - 1;
	for (int i = 0; i <= j; i++)
	{
		if (s[i] != s[j])
			return false;

		j--;
	}

	return true;
}

int main()
{

	int max = 0;
	for (int i = MAX; i >= 100; i--)
	{
		for (int j = MAX; j >= 100; j--)
		{
			float n = i * j;
			if (isPalindrome(n) && n > max)
				max = n;			
		}
	}

	cout << max << "\n";


	return 0;
}
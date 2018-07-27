#include <iostream>

using namespace std;

int main()
{
	int a = 0, b = 0;

	for (int i = 0; i <= 100; i++)
	{
		 a += i;
		 b += i * i;
	}

	a *= a;

	cout << a - b << "\n";

	cin.get();
	return 0;
}
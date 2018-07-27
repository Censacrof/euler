#include <iostream>

using namespace std;

int main()
{

	int s = 0;

	int f = 1;
	int f2 = 1;

	while (f <= 4000000)
	//for (int i = 0; i < 3; i++)
	{
		int swap = f;
		f += f2;
		f2 = swap;

		if (f % 2 == 0)
			s += f;
	}

	cout << s << "\n";

	return 0;
}
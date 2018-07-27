#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

struct couple {
	int s;
	string k;
	couple(string key, int score) { s = score; k = key; }
};

string xorEn(string s, string k)
{
	string n = "";
	for (int i = 0; i < s.size(); i++)
	{
		n += s[i] ^ k[i % k.size()];
	}

	return n;
}


string &sIncrement(string &s)
{
	bool done = false;
	for (int i = 0; !done && i < s.size(); i++)
	{
		done = true;
		s[i] = char(int(s[i]) + 1);

		if (s[i] > 'z')
		{
			s[i] = 'a';
			done = false;
		}
	}
}

int main()
{
	string s = "", buff;

	ifstream f("cipher.txt");
	while (f >> buff)
	{
		s += buff + " ";
	}

	for (unsigned i = 0; i < s.size(); i++)
		if (s[i] == ',')
			s[i] = ' ';

	stringstream ss(s);
	s = "";

	int c;
	while (ss >> c)
	{
		s += char(c);
	}


	couple max(".", 0);
	string en, i;
	for (i = "aaa"; i != "zzz"; sIncrement(i))
	{
		int score = 0;
		stringstream ssd(xorEn(s, i));
		string temp;

		while (ssd >> temp)
		{
			ifstream dict("dict.txt");
			string temp2;

			bool next = false;
			for (int j = 0; j < temp.size(); j++)
			{
				if (!(temp[j] >= 'A' && temp[j] <= 'Z' || temp[j] >= 'a' && temp[j] <= 'z'))
					next = true;
				if (temp[j] >= 'A' && temp[j] <= 'Z')
					temp[j] += 32;
			}

			if (next) continue;

			while (dict >> temp2)
			{
				if (temp.compare(temp2) == 0)
				{
					score++;
					break;
				}
			}


			dict.close();
		}

		if (score > max.s)
		{
			max = couple(i, score);
			//cout << "Key " << i << " got " << v.back().s << " occurrences\n";
		}
	}

	i = max.k;

	s = xorEn(s, i);
	cout << "\n\nbest key found is: '" << i << "' with " << max.s << " occurrences\n\n" << s << "\n\n";

	int sum = 0;
	for (int j = 0; j < s.size(); j++)
	{
		sum += int(s[j]);
	}
	
	cout << "\nThe sum of the ascii is: " << sum << "\n\n";

	return 0;
}
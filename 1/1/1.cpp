#include <iostream>
#include <vector>
#include <cassert>
#include <string>

using namespace std;

int main()
{
    vector<int> np(128, -1);
    vector<int> butt(128, -1);
	string s;


	for (int i = 1; i < 10; i++)
	{
		cin >> s;

		for (int j = 0; j < s.length(); j++)
		{
			int c = s[j];
			np[c] = j + 1;
			butt[c] = i;
		}
	}

	cin >> s;
	int l = 1;
	int up = 2;
	int f = 3;
	int stat = f;
	int last = 0;
	int cnt = 0;

	for (char c : s)
	{
		if (c == ' ')
		{
			cnt++;
			last = 0;
			continue;
		}

		if (butt[c] == last)
			cnt++;

		if (c == '.' || c == '?' || c == '!')
		{
			cnt += np[c];
			
			if(stat == l)
				stat = f;
			last = butt[c];
		}
		else
		{
			if ('a' <= c && c <= 'z')
			{
				cnt += np[c];
				if (stat == up || stat == f)
				{
					cnt++;
					stat = l;
				}
				last = butt[c];
			}
			else
			{
				if ('A' <= c && c <= 'Z')
				{
					cnt += np[c-'A'+'a'];

					if (stat == l)
					{
						cnt++;
						stat = up;
					}
					else
					{
						if (stat == f)
							stat = l;
						else
							assert(stat == up);

						last = butt[c - 'A' + 'a'];
					}
				}
			}
		}
	}


	cout << cnt;
}

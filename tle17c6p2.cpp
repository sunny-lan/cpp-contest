#include <iostream>
#include <string>
using namespace std;

int main()
{

	int n;
	string nm;
	cin >> n >> nm;
	for (int j = 0; j<n; j++)
	{
		string mk;
		ws(cin);
		getline(cin, mk);
		int st = 0;
		string num = "", den = "";
		bool nc = false, dc = false;
		int widx = 0;
		for (int i = 0; i<mk.length(); i++)
		{
			if (st == 0)
			{
				if (mk[i] == '/')
				{
					nc = true;
					st = 1;
				}
				else
				{
					num += mk[i];
				}
			}
			else if (st == 1)
			{
				if (mk[i] == ' ')
				{
					dc = true;
					st = 2;
				}
				else
				{
					den += mk[i];
				}
			}
			else if (st == 2)
			{
				//if()
				if (widx>nm.length()||mk[i] != nm[widx])
				{
					printf("N\n");
					goto outer;

				}
				widx++;
			}
		}
		if (nc )
		{
			int a = atoi(num.c_str()),
				b = atoi(den.c_str());
			if (a <= b)
			{
				printf("N\n");

				continue;
			}
		}

		printf("Y\n");
	outer: continue;
	}
}

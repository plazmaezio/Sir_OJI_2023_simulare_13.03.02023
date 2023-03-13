#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("sir.in");
ofstream fout("sir.out");


int main()
{
	int n, q, l, r;
	static int x[100000];
	fin >> n >> q;

	for (int i = 1; i <= n; i++)
		fin >> x[i];

	int newNumber = 0, sum = 0, decreaseSum = 0, lastNumber = 0, lastNumberAdded = 0;
	int* firstNumber;

	for (int qq = 1; qq <= q; qq++)
	{
		sum = 0;
		fin >> l >> r;
		if (r <= n)
		{
			for (int i = l; i <= r; i++)
			{
				sum += x[i];
			}
		}
		else
		{
			sum = 0;
			decreaseSum = 0;
			int ct = 0;

			firstNumber = &x[1];

			for (int i = 1; i <= n; i++)
			{
				sum += x[i];
				if (x[i] != 0)
					ct++;
				lastNumber = x[i];
				lastNumberAdded = x[i];
			}

			for (int i = 1; i <= r - n + 1; i++)
			{
				if (ct % 2 != 0)
				{
					newNumber = lastNumberAdded + 1;
					lastNumberAdded++;
					lastNumber = newNumber;
					sum += newNumber;

					firstNumber = firstNumber + 1;
					if (*firstNumber % 2 != 0)
					{
						ct--;
					}
					decreaseSum += *firstNumber;
				}
				else
				{
					newNumber = 0;
					lastNumber = 0;

					firstNumber = firstNumber + 1;
					if (*firstNumber % 2 != 0)
					{
						ct--;
					}

					decreaseSum += *firstNumber;
				}
				cout << "newNumber: " << newNumber << endl;
				cout << "lastNumber: " << lastNumber << endl;
				cout << "lastNumberAdded: " << lastNumberAdded << endl;
				cout << "firstNumber: " << *firstNumber << endl;
				cout << "decreaseSum: " << decreaseSum << endl;
				cout << "sum: " << sum << endl;
				cout << endl;
				cout << endl;
			}
		}
		fout << sum - decreaseSum << endl;
	}
}

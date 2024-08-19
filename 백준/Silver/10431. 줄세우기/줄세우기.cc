#include <bits/stdc++.h>

using namespace std;

int Solution(vector<int> Inputs)
{
	int answer = 0;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (Inputs[i] < Inputs[j])
			{
				int Temp = Inputs[i];
				for (int k = i; k > j; k--)
				{
					Inputs[k] = Inputs[k - 1];
					answer++;
				}
				Inputs[j] = Temp;
			}
		}
	}

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int P;

	cin >> P;

	for (int i = 0; i < P; i++)
	{
		vector<int> temp(20, 0);
		int testcase;
		cin >> testcase;

		for (int j = 0; j < 20; j++)
		{
			cin >> temp[j];
		}

		cout << testcase << " " << Solution(temp) << "\n";
	}

	return 0;
}

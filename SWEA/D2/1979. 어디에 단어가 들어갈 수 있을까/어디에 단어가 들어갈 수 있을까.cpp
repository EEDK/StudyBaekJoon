#include <bits/stdc++.h>

using namespace std;

int countWords(const vector<vector<int>>& puzzle, int N, int K)
{
	int count = 0;

	for (int i = 0; i < N; ++i)
	{
		int length = 0;
		for (int j = 0; j < N; ++j)
		{
			if (puzzle[i][j] == 1)
			{
				length++;
			}
			else
			{
				if (length == K) count++;
				length = 0;
			}
		}
		if (length == K) count++;
	}

	for (int j = 0; j < N; ++j)
	{
		int length = 0;
		for (int i = 0; i < N; ++i)
		{
			if (puzzle[i][j] == 1)
			{
				length++;
			}
			else
			{
				if (length == K) count++;
				length = 0;
			}
		}
		if (length == K) count++;
	}

	return count;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N, K;
		cin >> N >> K;

		vector<vector<int>> puzzle(N, vector<int>(N));
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				cin >> puzzle[i][j];
			}
		}

		int result = countWords(puzzle, N, K);
		cout << "#" << t << " " << result << endl;
	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

vector<int> ParentNode;

int find(int a)
{
	if (ParentNode[a] == a)
	{
		return a;
	}
	return ParentNode[a] = find(ParentNode[a]);  // 경로 압축
}

void Union(int a, int b)
{
	int rootA = find(a);
	int rootB = find(b);

	if (rootA != rootB)
	{
		ParentNode[rootB] = rootA; 
	}
}

bool checkSame(int a, int b)
{
	a = find(a);
	b = find(b);

	if (a == b)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	ParentNode.resize(N + 1);

	for (int i = 0; i < N + 1; i++)
	{
		ParentNode[i] = i;
	}

	for (int i = 0; i < M; i++)
	{
		int pt, a, b;
		cin >> pt >> a >> b;

		if (pt == 0)
		{
			Union(a, b);
		}
		else
		{
			if(checkSame(a, b)){
				cout << "YES" << "\n";
			}
			
			else{
				cout << "NO" << "\n";
			}
		}
	}

	return 0;
}

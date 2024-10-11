#include <bits/stdc++.h>

using namespace std;

int N, M;

void DecalComani(vector<vector<char>>& Graph)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (Graph[i][j] != '.')
            {
                Graph[i][M - j - 1] = Graph[i][j];
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    vector<vector<char>> Graph(N, vector<char>(M, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> Graph[i][j];
        }
    }

    DecalComani(Graph);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << Graph[i][j];
        }
        cout << "\n";
    }

    return 0;
}

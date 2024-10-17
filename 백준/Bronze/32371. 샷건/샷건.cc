#include <bits/stdc++.h>
#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

vector<string> KeyBoard(4, "");
string Inputs;

int dx[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

bool IsValid(int x, int y) {
    return x >= 0 && x < 4 && y >= 0 && y < 10;
}

bool IsFind(pair<int, int> Pos)
{
    string find = "";

    int x = Pos.first;
    int y = Pos.second;

    for (int i = 0; i < 9; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (IsValid(nx, ny)) {
            find += KeyBoard[nx][ny];
        }
    }

    sort(find.begin(), find.end());

    return find == Inputs;
}

int main()
{
    FASTIO

    FOR(i, 4)
    {
        cin >> KeyBoard[i];
    }

    cin >> Inputs;

    sort(Inputs.begin(), Inputs.end());

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (IsFind({i, j}))
            {
                cout << KeyBoard[i][j] << endl;
                return 0;
            }
        }
    }

    return 0;
}

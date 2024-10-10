#include <bits/stdc++.h>

using namespace std;

string QuadTree;

bool CheckUniform(const vector<vector<int>>& A, int y, int x, int size) {
    int value = A[y][x];
    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (A[i][j] != value) {
                return false;
            }
        }
    }
    return true;
}

void GetQuadTree(const vector<vector<int>>& A, int y, int x, int size) {
    if (CheckUniform(A, y, x, size)) {
        QuadTree += to_string(A[y][x]);
        return;
    }

    QuadTree += '(';

    int half = size / 2;
    GetQuadTree(A, y, x, half);
    GetQuadTree(A, y, x + half, half);
    GetQuadTree(A, y + half, x, half);
    GetQuadTree(A, y + half, x + half, half);

    QuadTree += ')';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<vector<int>> A(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
    {
        string row;
        cin >> row;
        for (int j = 0; j < N; j++)
        {
            A[i][j] = row[j] - '0';
        }
    }

    GetQuadTree(A, 0, 0, N);

    cout << QuadTree << "\n";

    return 0;
}

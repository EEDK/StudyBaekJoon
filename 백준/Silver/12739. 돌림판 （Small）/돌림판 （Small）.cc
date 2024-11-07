#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define INF (~0U >> 2)
#define PB push_back

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int N, K;
string str;

void Change()
{
    string new_str = str;
    for (int i = 0; i < N; i++)
    {
        int Rcnt = 0, Gcnt = 0, Bcnt = 0;

        int left = (i - 1 + N) % N;
        int right = (i + 1) % N;

        char colors[3] = {str[left], str[i], str[right]};
        for (char c : colors)
        {
            if (c == 'R') Rcnt++;
            else if (c == 'G') Gcnt++;
            else if (c == 'B') Bcnt++;
        }

        if (Rcnt == 3 || Gcnt == 3 || Bcnt == 3 || (Rcnt == 1 && Gcnt == 1 && Bcnt == 1))
        {
            new_str[i] = 'B';
        }
        else if ((Rcnt == 2 && Gcnt == 1) || (Gcnt == 2 && Bcnt == 1) || (Bcnt == 2 && Rcnt == 1))
        {
            new_str[i] = 'R';
        }
        else
        {
            new_str[i] = 'G';
        }
    }
    str = new_str;
}


int main()
{
    FASTIO

    cin >> N >> K;
    cin >> str;

    while (K--)
    {
        Change();
    }

    int Rcnt = count(str.begin(), str.end(), 'R');
    int Gcnt = count(str.begin(), str.end(), 'G');
    int Bcnt = count(str.begin(), str.end(), 'B');

    cout << Rcnt << " " << Gcnt << " " << Bcnt << endl;

    return 0;
}

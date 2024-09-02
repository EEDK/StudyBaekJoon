#include <iostream>
#include <vector>

using namespace std;

long long count = 0;
int n;

vector<int> col;
vector<int> diag1;
vector<int> diag2;

void search(int y)
{
    if (y == n)
    {
        count++;
        return;
    }

    for (int x = 0; x < n; x++)
    {
        if (col[x] || diag1[x + y] || diag2[x - y + n - 1]) continue;

        col[x] = diag1[x + y] = diag2[x - y + n - 1] = 1;
        search(y + 1);
        col[x] = diag1[x + y] = diag2[x - y + n - 1] = 0; 
    }
}

int main()
{
    cin >> n;

    col.resize(n, 0);
    diag1.resize(2 * n - 1, 0);
    diag2.resize(2 * n - 1, 0);

    search(0);

    cout << count << endl;

    return 0;
}

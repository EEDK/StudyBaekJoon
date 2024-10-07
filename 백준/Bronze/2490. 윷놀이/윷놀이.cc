#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 3; i++)
    {
        int front = 0;
        int back = 0;

        for (int j = 0; j < 4; j++)
        {
            int temp;
            cin >> temp;

            if (temp == 0)
            {
                front++;
            }
            else
            {
                back++;
            }
        }

        if (front == 0)
        {
            cout << "E" << "\n";
        }
        if (front == 1)
        {
            cout << "A" << "\n";
        }
        if (front == 2)
        {
            cout << "B" << "\n";
        }
        if (front == 3)
        {
            cout << "C" << "\n";
        }
        if (front == 4)
        {
            cout << "D" << "\n";
        }
    }


    return 0;
}

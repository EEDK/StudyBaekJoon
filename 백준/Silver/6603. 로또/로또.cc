#include <bits/stdc++.h>

using namespace std;

vector<int> Temp;

void PrintArr(vector<int> Arr)
{
    for (const auto& item : Arr)
    {
        cout << item << " ";
    }

    cout << "\n";
}

void BackTrack(vector<int>& Inputs, int Pos)
{
    if (Temp.size() == 6)
    {
        PrintArr(Temp);
        return;
    }

    // 탐색 종료 조건
    if (Pos >= Inputs.size())
    {
        return;
    }

    Temp.push_back(Inputs[Pos]);
    BackTrack(Inputs, Pos + 1);

    Temp.pop_back();
    BackTrack(Inputs, Pos + 1);
}

void Solve(vector<int>& Inputs)
{
    BackTrack(Inputs, 0);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bool first = true;
    while (true)
    {
        int K;
        cin >> K;
        if (K == 0)
        {
            break;
        }
        vector<int> Inputs(K, 0);

        for (int i = 0; i < K; i++)
        {
            cin >> Inputs[i];
        }

        Solve(Inputs);
        cout << "\n";
    }

    return 0;
}

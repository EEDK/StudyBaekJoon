#include <bits/stdc++.h>

using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;

    vector<int> Inputs(W, 0);

    for (int i = 0; i < W; i++)
    {
        cin >> Inputs[i];
    }

    vector<int> leftMax(W, 0), rightMax(W, 0);

    leftMax[0] = Inputs[0];
    for (int i = 1; i < W; i++)
    {
        leftMax[i] = max(leftMax[i - 1], Inputs[i]);
    }

    rightMax[W - 1] = Inputs[W - 1];
    for (int i = W - 2; i >= 0; i--)
    {
        rightMax[i] = max(rightMax[i + 1], Inputs[i]);
    }

    int answer = 0;
    for (int i = 0; i < W; i++)
    {
        answer += min(leftMax[i], rightMax[i]) - Inputs[i];
    }

    cout << answer << "\n";

    return 0;
}
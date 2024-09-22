#include <bits/stdc++.h>

using namespace std;

int Solve(const vector<int>& histogram)
{
    int n = histogram.size();
    stack<int> s;
    int maxArea = 0;

    for (int i = 0; i <= n; ++i)
    {
        int currentHeight = (i == n ? 0 : histogram[i]);

        while (!s.empty() && currentHeight < histogram[s.top()])
        {
            int h = histogram[s.top()];
            s.pop();
            int width = s.empty() ? i : i - s.top() - 1;
            maxArea = max(maxArea, h * width);
        }
        s.push(i);
    }

    return maxArea;
}

int main()
{
    int N;
    cin >> N;

    vector<int> T(N, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> T[i];
    }

    cout << Solve(T) << "\n";

    return 0;
}

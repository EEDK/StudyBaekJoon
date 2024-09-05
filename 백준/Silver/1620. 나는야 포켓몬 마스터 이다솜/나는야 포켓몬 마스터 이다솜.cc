#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M;

    cin >> N >> M;

    vector<string> Doram(N);
    unordered_map<string, int> nameToNumber;

    for (int i = 0; i < N; i++)
    {
        cin >> Doram[i];
        nameToNumber[Doram[i]] = i + 1;
    }

    vector<string> answer;
    for (int i = 0; i < M; i++)
    {
        string input;
        cin >> input;

        if (isdigit(input[0]))
        {
            int index = stoi(input);
            answer.push_back(Doram[index - 1]);
        }
        else
        {
            answer.push_back(to_string(nameToNumber[input]));
        }
    }

    for (int i = 0; i < M; i++)
    {
        cout << answer[i] << "\n";
    }

    return 0;
}

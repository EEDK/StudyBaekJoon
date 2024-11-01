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

int Solve(vector<pair<char, int>> Inputs)
{
    vector<int> numbers;
    unordered_map<char, int> color_count;
    unordered_map<int, int> number_count;

    for (auto& card : Inputs)
    {
        color_count[card.first]++;
        number_count[card.second]++;
        numbers.PB(card.second);
    }

    sort(numbers.begin(), numbers.end());

    int maxNum = numbers[4];
    bool same_color = (color_count.size() == 1);
    bool consecutive = true;

    for (int i = 1; i < 5; i++)
    {
        if (numbers[i] != numbers[i - 1] + 1)
        {
            consecutive = false;
            break;
        }
    }

    int score = 0;

    // 1번 조건: 같은 색상이고 숫자가 연속적일 때
    if (same_color && consecutive)
    {
        score = max(score, 900 + maxNum);
    }

    // 2번 조건: 4장이 같은 숫자일 때
    for (auto& entry : number_count)
    {
        if (entry.second == 4)
        {
            score = max(score, 800 + entry.first);
        }
    }

    // 3번 조건: 3장이 같은 숫자이고 2장이 같은 숫자일 때 (풀 하우스)
    int three_num = 0, two_num = 0;
    for (auto& entry : number_count)
    {
        if (entry.second == 3) three_num = entry.first;
        if (entry.second == 2) two_num = entry.first;
    }
    if (three_num && two_num)
    {
        score = max(score, 700 + three_num * 10 + two_num);
    }

    // 4번 조건: 5장이 같은 색상일 때
    if (same_color)
    {
        score = max(score, 600 + maxNum);
    }

    // 5번 조건: 숫자가 연속적일 때
    if (consecutive)
    {
        score = max(score, 500 + maxNum);
    }

    // 6번 조건: 3장이 같은 숫자일 때
    for (auto& entry : number_count)
    {
        if (entry.second == 3)
        {
            score = max(score, 400 + entry.first);
        }
    }

    // 7번 조건: 2장이 같은 숫자이고 또 다른 2장이 같은 숫자일 때 (투 페어)
    vector<int> pairs;
    for (auto& entry : number_count)
    {
        if (entry.second == 2) pairs.PB(entry.first);
    }
    if (pairs.size() == 2)
    {
        score = max(score, 300 + max(pairs[0], pairs[1]) * 10 + min(pairs[0], pairs[1]));
    }

    // 8번 조건: 2장이 같은 숫자일 때
    if (!pairs.empty())
    {
        score = max(score, 200 + pairs[0]);
    }

    // 9번 조건: 위의 어떤 경우에도 해당하지 않을 때
    score = max(score, 100 + maxNum);

    return score;
}

int main()
{
    FASTIO;
    vector<pair<char, int>> Inputs;

    FOR(i, 5)
    {
        char Color;
        int Number;
        cin >> Color >> Number;

        Inputs.PB({Color, Number});
    }

    cout << Solve(Inputs) << endl;

    return 0;
}

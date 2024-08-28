#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<string> inputs;
    string line;

    while (true)
    {
        getline(std::cin, line);
        if (line == ".") break;
        inputs.push_back(line);
    }

    for (const auto& input : inputs)
    {
        stack<char> Stack;

        bool isOk = true;
        for (auto s : input)
        {
            if (s == '(' || s == '[')
            {
                Stack.push(s);
            }

            else if (s == ')')
            {
                if (Stack.empty() || Stack.top() != '(')
                {
                    cout << "no" << "\n";
                    isOk = false;
                    break;
                }
                Stack.pop();
            }
            else if (s == ']')
            {
                if (Stack.empty() || Stack.top() != '[')
                {
                    cout << "no" << "\n";
                    isOk = false;
                    break;
                }
                Stack.pop();
            }
        }

        if (Stack.empty() && isOk)
        {
            cout << "yes" << "\n";
        }
        else if (isOk)
        {
            cout << "no" << "\n";
        }
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> A(N, 0);
    vector<char> resultV;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    stack<int> Stack;
    int num = 1;
    bool result = true;

    for (int i = 0; i < N; i++) {
        int su = A[i];

        if (su >= num) {
            while (su >= num) {
                Stack.push(num++);
                resultV.push_back('+');
            }
            Stack.pop();
            resultV.push_back('-');
        }
        
        else{
            int n = Stack.top();
            Stack.pop();

            if (n > su){
                cout << "NO";
                result = false;
                break;
            }
            else{
                resultV.push_back('-');
            }
        }
    }
    
    if(result){
        for (auto Item : resultV){
            cout << Item << "\n";
        }
    }

    return 0;
}

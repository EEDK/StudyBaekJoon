#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> Input(N, 0);

    for (int i = 0; i < N; ++i) {
        cin >> Input[i];
    }

    sort(Input.begin(), Input.end());

    int cnt = 0;
    int startPos = 0;
    int endPos = N - 1;
    
    while(startPos < endPos){
        int sum = Input[startPos] + Input[endPos];
        if (sum == M){
            cnt++;
            startPos++;
            endPos--;
        }
        
        else if(sum > M){
            endPos--;
        }
        
        else{
            startPos++;
        }
    }
    
    cout << cnt << endl;
    
    return 0;
}

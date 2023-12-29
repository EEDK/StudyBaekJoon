#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> inputs, int target) {
    int start = 0;
    int end = *max_element(inputs.begin(), inputs.end());
    int result = 0;

    while (start <= end) {
        long long sum = 0;
        int mid = (start + end) / 2;
        for (auto i = 0; i < inputs.size(); i++) {
            if (inputs[i] > mid) sum += inputs[i] - mid;
        }
        if (sum >= target) {
            result = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return result;
}

int main() {
//    freopen("./input.txt", "r", stdin);
    int N, Target;
    cin >> N >> Target;
    vector<int> inputs;

    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        inputs.push_back(tmp);
    }

    cout << solution(inputs, Target) << endl;

    return 0;
}

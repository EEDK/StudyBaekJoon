#include <bits/stdc++.h>
#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

int N, K;

int main() {
    FASTIO

    cin >> N >> K;
    vector<int> Inputs(2 * N, 0);  // 내구도 저장
    vector<bool> hasRobot(2 * N, false);  // 로봇이 있는지 여부 저장

    FOR(i, 2*N) {
        cin >> Inputs[i];
    }

    int step = 0;  // 현재 단계
    int pos = 0;   // 로봇 위치

    while (true) {
        step++;

        // 1. 벨트가 회전한다.
        rotate(Inputs.begin(), Inputs.begin() + (2 * N - 1), Inputs.end());
        rotate(hasRobot.begin(), hasRobot.begin() + (2 * N - 1), hasRobot.end());

        // 2. 로봇 내리기
        if (hasRobot[N - 1]) {
            hasRobot[N - 1] = false;  // 내리는 위치에서 로봇을 내린다.
        }

        // 3. 로봇 이동
        for (int i = N - 2; i >= 0; i--) {
            if (hasRobot[i] && !hasRobot[i + 1] && Inputs[i + 1] > 0) {
                hasRobot[i] = false;
                hasRobot[i + 1] = true;
                Inputs[i + 1]--;  // 이동한 칸의 내구도를 감소시킨다.
            }
        }

        // 4. 로봇 내리기
        if (hasRobot[N - 1]) {
            hasRobot[N - 1] = false;  // 내리는 위치에서 로봇을 내린다.
        }

        // 5. 올리는 위치에 로봇을 올린다.
        if (Inputs[0] > 0) {
            hasRobot[0] = true;
            Inputs[0]--;
        }

        // 6. 내구도가 0인 칸이 K개 이상이면 종료
        if (count(Inputs.begin(), Inputs.end(), 0) >= K) {
            cout << step << endl;
            break;
        }
    }

    return 0;
}

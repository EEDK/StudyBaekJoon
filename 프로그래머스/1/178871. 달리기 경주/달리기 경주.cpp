#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    unordered_map<string, int> playerIndices;  
    int size = players.size();
    answer = players;

    for (int i = 0; i < size; i++) {
        playerIndices[players[i]] = i;
    }

    for (const auto &calledPlayer : callings) {
        int idx = playerIndices[calledPlayer];
        if (idx > 0) {
            swap(answer[idx], answer[idx - 1]);
            playerIndices[calledPlayer] = idx - 1;
            playerIndices[answer[idx]] = idx;
        }
    }

    return answer;
}

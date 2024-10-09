#include <bits/stdc++.h>

using namespace std;

set<set<string>> resultSet;

bool isMatch(string user, string banned) {
    if (user.size() != banned.size()) return false;
    for (int i = 0; i < user.size(); i++) {
        if (banned[i] != '*' && user[i] != banned[i]) return false;
    }
    return true;
}

void backtrack(vector<string>& user_id, vector<string>& banned_id, vector<bool>& visited, int idx, set<string>& currentSet) {
    if (idx == banned_id.size()) {
        resultSet.insert(currentSet);
        return;
    }
    
    for (int i = 0; i < user_id.size(); i++) {
        if (!visited[i] && isMatch(user_id[i], banned_id[idx])) {
            visited[i] = true;
            currentSet.insert(user_id[i]);
            backtrack(user_id, banned_id, visited, idx + 1, currentSet);
            currentSet.erase(user_id[i]);
            visited[i] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    vector<bool> visited(user_id.size(), false);
    set<string> currentSet;
    backtrack(user_id, banned_id, visited, 0, currentSet);
    return resultSet.size();
}

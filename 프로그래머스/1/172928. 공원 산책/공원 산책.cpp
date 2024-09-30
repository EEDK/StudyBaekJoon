#include <bits/stdc++.h>

using namespace std;

int N, M;

bool IsValid(vector<string>& park, pair<int, int> Pos) {
    return (Pos.first >= 0 && Pos.first < N && Pos.second >= 0 && Pos.second < M && park[Pos.first][Pos.second] != 'X');
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    
    N = park.size();
    M = park[0].size();

    pair<int, int> Pos;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (park[i][j] == 'S') {
                Pos = {i, j};
            }
        }
    }
    
    for (const auto& route : routes) {
        char op = route[0];
        int distance = stoi(route.substr(2));
        
        pair<int, int> tempPos = Pos;
        bool IsOk = true;
        switch (op) {
            case 'N':
                for (int i = 0; i < distance; i++) {
                    tempPos.first--;
                    if (!IsValid(park, tempPos)) {
                        IsOk = false;
                        break;
                    }
                }
                break;
            case 'S':
                for (int i = 0; i < distance; i++) {
                    tempPos.first++;
                    if (!IsValid(park, tempPos)) {
                        IsOk = false;
                        break;
                    }
                }
                break;
            case 'W':
                for (int i = 0; i < distance; i++) {
                    tempPos.second--;
                    if (!IsValid(park, tempPos)) {
                        IsOk = false;
                        break;
                    }
                }
                break;
            case 'E':
                for (int i = 0; i < distance; i++) {
                    tempPos.second++;
                    if (!IsValid(park, tempPos)) {
                        IsOk = false;
                        break;
                    }
                }
                break;
            default:
                break;
        }
        
        if (IsOk) {
            Pos = tempPos;
        }
    }
    
    answer.push_back(Pos.first);
    answer.push_back(Pos.second);
    
    return answer;
}

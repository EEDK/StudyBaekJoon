#include <bits/stdc++.h>

using namespace std;

vector<int> answer = {0, 0};
vector<int> discounts = {10, 20, 30, 40}; 

void calculate(vector<vector<int>>& users, vector<int>& emoticons, vector<int>& discount_combination) {
    int subscription_count = 0;
    int sales = 0;

    for (auto& user : users) {
        int user_rate = user[0]; 
        int user_price_limit = user[1]; 
        int total_price = 0;

        for (int i = 0; i < emoticons.size(); ++i) {
            if (discount_combination[i] >= user_rate) {
                total_price += emoticons[i] * (100 - discount_combination[i]) / 100;
            }
        }

        if (total_price >= user_price_limit) {
            subscription_count++;
        } else {
            sales += total_price;
        }
    }

    if (subscription_count > answer[0]) {
        answer = {subscription_count, sales};
    } else if (subscription_count == answer[0] && sales > answer[1]) {
        answer[1] = sales;
    }
}

void dfs(vector<vector<int>>& users, vector<int>& emoticons, vector<int>& discount_combination, int depth) {
    if (depth == emoticons.size()) {
        calculate(users, emoticons, discount_combination);
        return;
    }

    for (int i = 0; i < discounts.size(); ++i) {
        discount_combination[depth] = discounts[i]; 
        dfs(users, emoticons, discount_combination, depth + 1); 
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> discount_combination(emoticons.size()); 
    dfs(users, emoticons, discount_combination, 0); 
    return answer;
}

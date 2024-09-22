#include <bits/stdc++.h>

using namespace std;

void Heal(int &health, const int& max_health, const int& heal_amount){
    if(health + heal_amount >= max_health){
        health = max_health;
    }
    else{
        health += heal_amount;
    }
}

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int maxHealth = health;
    int t = bandage[0];
    int x = bandage[1];
    int y = bandage[2]; 

    int currentHealth = health;
    int consecutiveTime = 0;

    int attackIndex = 0;
    int totalAttackEvents = attacks.size();

    for (int time = 1; ; ++time) {
        if (attackIndex < totalAttackEvents && attacks[attackIndex][0] == time) {
            int damage = attacks[attackIndex][1];
            currentHealth -= damage;

            if (currentHealth <= 0) {
                return -1; 
            }

            consecutiveTime = 0;
            attackIndex++;
        } else {
            if (consecutiveTime < t) {
                currentHealth += x;
                if (currentHealth > maxHealth) {
                    currentHealth = maxHealth;
                }
                consecutiveTime++;
            }

            if (consecutiveTime == t) {
                currentHealth += y;
                if (currentHealth > maxHealth) {
                    currentHealth = maxHealth;
                }
                consecutiveTime = 0;
            }
        }

        if (attackIndex >= totalAttackEvents) {
            break;
        }
    }

    return currentHealth;
}
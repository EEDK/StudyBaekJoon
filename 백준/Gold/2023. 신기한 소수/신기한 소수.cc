#include <bits/stdc++.h>

using namespace std;

static int N;

bool isPrime(int n) {
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

void DFS(int number, int jarisu) {
    if (jarisu == N) {
        if (isPrime(number)) {
            cout << number << "\n";
        }
        return;
    }
    
    for(int i = 1; i < 10; i++){
        if(i % 2 == 0){
            continue;
        }
        else if(isPrime(number * 10 + i)){
            DFS(number*10 + i, jarisu + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    DFS(2, 1);
    DFS(3, 1);
    DFS(5, 1);
    DFS(7, 1);
    

    return 0;
}

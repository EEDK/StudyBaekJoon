#include <vector>

using namespace std;

const int MOD = 1234567;

vector<int> fib_cache;

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    if (fib_cache[n] != -1) {
        return fib_cache[n];
    }
    
    fib_cache[n] = (fibonacci(n - 1) + fibonacci(n - 2)) % MOD;
    return fib_cache[n];
}

int solution(int n) {
    fib_cache = vector<int>(n + 1, -1);
    return fibonacci(n);
}
// Calculate nCr using inverse modulo and print the result by taking mod from 10^9 + 7.
#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
// Function to calculate a^b % m
long long binpow(long long a, long long b, long long m) {
    long long result = 1;
    while (b) {
        if (b & 1)
            result = (result * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return result;
}
// Precompute factorials and their inverses
void precompute_factorials(vector<long long>& fact, vector<long long>& inv_fact, int max_n) {
    fact[0] = 1;
    for (int i = 1; i <= max_n; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    inv_fact[max_n] = binpow(fact[max_n], MOD - 2, MOD); // Compute inverse of max_n!
    for (int i = max_n - 1; i >= 0; i--) {
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
    }
}
// Function to calculate nCr % MOD
long long nCr(int n, int r, const vector<long long>& fact, const vector<long long>& inv_fact) {
    if (r > n || r < 0) return 0;
    return fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD;
}
int main() {
    int n, r;
    cout << "Enter n and r: ";
    cin >> n >> r;
    const int MAX_N = 100000; // Adjust based on problem constraints
    vector<long long> fact(MAX_N + 1), inv_fact(MAX_N + 1);
    precompute_factorials(fact, inv_fact, MAX_N);
    cout << "nCr(" << n << ", " << r << ") % " << MOD << " = " << nCr(n, r, fact, inv_fact) << endl;
    return 0;
}

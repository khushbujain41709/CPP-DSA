//Calculate the inverse factorial of the first 10 natural numbers. Modulo the result by 10^9 + 7.
// The modular inverse of a mod m is exists if m is prime and can be calculated using : a^(-1) mod m = a^(m-2) mod m
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
int main() {
    const int N = 10; // First 10 natural numbers
    vector<long long> fact(N + 1, 1); // Factorials mod MOD
    vector<long long> inv_fact(N + 1, 1); // Inverse factorials mod MOD
    // Compute factorials modulo MOD
    for (int i = 2; i <= N; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    // Compute inverse factorials modulo MOD
    for (int i = 1; i <= N; i++) {
        inv_fact[i] = binpow(fact[i], MOD - 2, MOD); // Modular inverse using binpow
    }
    // Output the results
    for (int i = 1; i <= N; i++) {
        cout << "Inverse factorial of " << i << " (modulo " << MOD << "): " << inv_fact[i] << endl;
    }
    return 0;
}

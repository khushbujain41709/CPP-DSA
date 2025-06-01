// Find a to the power b to the power c.Modulo the result by 10^9 + 7.
#include <bits/stdc++.h>
using namespace std;
long long binpow(long long a, long long b, long long m){
    long long ans = 1;
    while (b){
        if (b & 1) // if b is odd
            ans = (ans * a) % m;
        b /= 2;
        a = (a * a) % m;
    }
    return ans;
}
int main(){
    long long a, b, c;
    cin >> a >> b >> c;
    const long long M = 1e9 + 7;
    cout << binpow(a, binpow(b, c, M), M);
}
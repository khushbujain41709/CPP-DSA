// Given an integer n, find the largest and smallest power of two that is set in that integer.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int smallest = -1, largest = -1;
    for (int i = 0; i < 31; i++){ // Bit positions are 0 to 31 (i.e., 32 bits total) but goes only upto 30 only to avoid sign bit
        if (n & (1 << i)) {
            smallest = i;
            break;
        }
    }
    for (int i = 30; i >= 0; i--){
        if (n & (1 << i)) {
            largest = i;
            break;
        }
    }
    cout << smallest << " " << largest << '\n';
    /*
    | i  | 1 << i | Binary              |
    | -- | ------ | ------------------- |
    | 0  | 1      | 000000...0000000001 |
    | 1  | 2      | 000000...0000000010 |
    | 2  | 4      | 000000...0000000100 |
    | 3  | 8      | 000000...0000001000 |
    | 4  | 16     | 000000...0000010000 |
    | .. | ..     | ...                 |

    */
}
// Check if a number is a power of two or not using bitwise operations.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    if ((n & (n - 1)) == 0) {
        cout << "YES\n";
    } 
    else {
        cout << "NO\n";
    }
}
// Given an integer n, find the minimum number to be added to change it to a power of two. (Try using bitmasking)
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    if ((n & (n - 1)) == 0) { // if already a power of 2
        cout << 0;
        return 0;
    }
    int p = 0, temp = n;
        while (temp > 0) {
        temp /= 2;
        p++;
    }
    int nearest = 1 << p;
    cout << nearest - n << '\n';
}
// Given an array consisting of integers a and b where a is occurring even number of times. Find the value of a and b. (Try using bit operations to solve)
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int b = 0;
    for (int i = 0; i < n; i++) {
        b ^= v[i];
    }
    int a;
    if (b == v[0]) {
        a = v[1];
    } 
    else {
        a = v[0];
    }
    cout << a << " " << b << '\n';
}
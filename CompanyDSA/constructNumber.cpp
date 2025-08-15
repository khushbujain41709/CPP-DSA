// Codechef question
// You are given an integer N. Your task is to help Chef find an N-digit odd positive integer X such that:
// X is divisible by 3
// X is not divisible by 9
// X has no leading zeroes
#include<iostream>
#include<vector>
using namespace std;

// approach 1 : wrong one gives tle
string construct(int n){
    // Base idea: make first (n-1) digits = 1 and last digit = 1 or 3 or 5 or 7 or 9
    // So total digit sum = (n-1)*1 + last_digit
    vector<int> oddDigits = {1,3,5,7,9};
    for(int i = 0; i<oddDigits.size(); i++){
        int sum = (n-1)*1 + oddDigits[i];
        if(sum % 3 == 0 && sum % 9 != 0){
            string ans(n - 1, '1');
            ans += (oddDigits[i] + '0' );
            return ans;
        }
    }
}
int main() {
	int tasty;
	cin>>tasty;
	while(tasty --){
	    int n;
	    cin>>n;
	    cout<<construct(n)<<endl;
	}
}

// approach 2 : A more straightforward approach is to construct a number of the form 300...03. This number is always odd, and the sum of its digits is 6, which is divisible by 3 but not by 9.
#include <iostream>
#include <string>
using namespace std;
string construct(int n) {
    if (n == 1) {
        return "3";
    }
    string ans = "3";
    for (int i = 0; i < n - 2; ++i) {
        ans += "0";
    }
    ans += "3";
    return ans;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << construct(n) << endl;
    }
    return 0;
}
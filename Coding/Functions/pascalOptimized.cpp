// Leetcode 118
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> generate(int numRows){
    int n = numRows;
    vector<vector<int>> result;
    for(int i = 0; i< n; i++){
        int curr = 1;
        vector<int> ans;
        for(int j = 0; j<= i; j++){
            ans.push_back(curr);
            curr = curr*(i-j)/(j+1);
        }
        result.push_back(ans);
    }
    return result;
}
int main(){
    int n ;
    cout<<"Enter number of lines in pascal Triangle : ";
    cin>>n;
    for(int i = 0;i<=n;i++){
        int curr = 1;
        for(int j= 0 ; j<=i;j++){
            cout<<curr<<" ";
            curr = curr*(i-j)/(j+1);  // as I want to print curr evertime.
            // calculated as ncr+1 = ncr*(n-r)/r+1
        }
        cout<<endl;
    }
    return 0;
}
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
vector<int> countingSort(vector<int>& input){
    int maxx = INT_MIN;
    for(int i = 0;i<input.size();i++){
        maxx = max(maxx , input[i]);
    }
    // making count array
    vector<int> count(maxx+1,0); // imp make (maxx + 1) size
    for(int i = 0;i<input.size();i++){
        count[input[i]] ++;
    }
    // making prefix sum array
    for(int i = 1;i<count.size();i++){
        count[i] = count[i] + count[i-1];
    }
    // making output array
    vector<int> output(input.size());
    for(int i = input.size() - 1; i >= 0; i--){ // traversing in reverse for stability.
        output[count[input[i]] - 1] = input[i];
        count[input[i]] = count[input[i]] - 1;
    }
    return output;
} 
vector<int> countingSortNeg(vector<int>& input) {
    int maxx = INT_MIN, minn = INT_MAX;
    for (int num : input) {
        maxx = max(maxx, num);
        minn = min(minn, num);
    }
    int range = maxx - minn + 1;     // Total range of numbers
    int offset = -minn;              // Offset to handle negative numbers
    // Step 1: Create count array
    vector<int> count(range, 0);
    for (int num : input) {
        count[num + offset]++;
    }
    // Step 2: Prefix sum (cumulative count)
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }
    // Step 3: Build output array (process from right to left for stability)
    vector<int> output(input.size());
    for (int i = input.size() - 1; i >= 0; i--) {
        output[count[input[i] + offset] - 1] = input[i];
        count[input[i] + offset]--;
    }
    return output;
}
int main(){
    vector<int> v = {5,1,8,2,7,6,3,4};
    int n = v.size();
    vector<int> ans;
    ans = countingSort(v);
    for(int i = 0;i<n;i++){
        cout<<ans[i] <<" ";
    }
    cout << endl;

    vector<int> vec = {5, -1, 8, 2, -7, 6, 3, -4 ,0};
    vector<int> ans2 = countingSortNeg(vec);
    for (int num : ans2) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}

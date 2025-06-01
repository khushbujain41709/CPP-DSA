// Leetcode 503
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, -1);
    stack<int> st;
    // Traverse the array twice in reverse to simulate circular behavior
    for(int i = 2 * n - 1; i >= 0; i--) {
        int curr = nums[i % n];
        while(!st.empty() && st.top() <= curr) {
            st.pop();
        }
        if(i < n) {
            if(!st.empty()) {
                ans[i] = st.top();
            }
            else{
                ans[i] = -1;
            }
        }
        st.push(curr);
    }
    return ans;
}
/*
Dry Run :
nums = [1, 2, 3, 4, 3]
n = 5

Loop from i = 9 to 0:

🔹 i = 9 → nums[9 % 5] = nums[4] = 3
Stack: empty → nothing to pop
i < n? ❌ (9 ≥ 5) → don’t assign ans
Push 3 → stack = [3]

🔹 i = 8 → nums[8 % 5] = nums[3] = 4
stack.top() = 3 ≤ 4 → pop → stack = []
i < n? ❌ → don’t assign
Push 4 → stack = [4]

🔹 i = 7 → nums[2] = 3
stack.top() = 4 > 3 → keep it
i < n?  (7 < 5 is false) → ❌
Push 3 → stack = [4, 3]

🔹 i = 6 → nums[1] = 2
stack.top() = 3 > 2 → keep it
i < n? ❌
Push 2 → stack = [4, 3, 2]

🔹 i = 5 → nums[0] = 1
stack.top() = 2 > 1 → keep it
i < n? ❌
Push 1 → stack = [4, 3, 2, 1]
Now i < n (for i = 4 to 0) — time to fill the answers.

🔹 i = 4 → nums[4] = 3
stack.top() = 1 ≤ 3 → pop(1)
stack.top() = 2 ≤ 3 → pop(2)
stack.top() = 3 == 3 → pop(3)
stack.top() = 4 > 3 → found!
✅ ans[4] = 4
Push 3 → stack = [4, 3]

🔹 i = 3 → nums[3] = 4
stack.top() = 3 ≤ 4 → pop(3)
stack.top() = 4 == 4 → pop(4)
Stack empty → ✅ ans[3] = -1
Push 4 → stack = [4]

🔹 i = 2 → nums[2] = 3
stack.top() = 4 > 3 → ✅ ans[2] = 4
Push 3 → stack = [4, 3]
🔹 i = 1 → nums[1] = 2
stack.top() = 3 > 2 → ✅ ans[1] = 3
Push 2 → stack = [4, 3, 2]

🔹 i = 0 → nums[0] = 1
stack.top() = 2 > 1 → ✅ ans[0] = 2
Push 1 → stack = [4, 3, 2, 1]
*/
int main(){
    
    return 0;
}
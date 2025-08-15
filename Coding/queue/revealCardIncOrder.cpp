// Leetcode 950
// pehle deck ko sort kr do the sorted elements ko fill krna hai ek new array mei
// ek ek space thod k elements ko bharna hai , for this we need index like where to store elements
// use queue for this, put firts element at q.front index then pop it and then do q.push(q.front) repeat this process
#include<iostream>
#include<vector>
#include<queue>
#include<Algorithm>
using namespace std;
vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        int n = deck.size();
        queue<int> q;
        for(int i = 0;i<n;i++){
            q.push(i);
        }
        vector<int> ans(n);
        for(int i = 0;i<n;i++){
            int index = q.front();
            q.pop();
            q.push(q.front());
            q.pop();
            ans[index] = deck[i];
        }
        return ans;
    }
int main(){
    
    return 0;
}
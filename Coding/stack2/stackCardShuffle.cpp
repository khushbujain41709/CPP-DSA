/*
// CodeForces Div 2 D - Cheater 15th June 2025
You are playing a new card game in a casino with the following rules: The game uses a deck of 2n cards with different values. The deck is evenly split between the player and the dealer: each receives n cards. Over n rounds, the player and the dealer simultaneously play one top card from their hand. The cards are compared, and the point goes to the one whose card has a higher value. The winning card is removed from the game, while the losing card is returned to the hand and placed on top of the other cards in the hand of the player who played it.
Note that the game always lasts exactly n rounds.
You have tracked the shuffling of the cards and know the order of the cards in the dealer's hand (from top to bottom). You want to maximize your score, so you can swap any two cards in your hand no more than once (to avoid raising suspicion).
Determine the maximum number of points you can achieve.
Input : Each test contains multiple test cases. The first line contains the number of test cases t. 
The first line of each test case contains a single integer n.
The second line of each test case contains n integers a1,a2,…,an the values of the cards in the player's hand from top to bottom.
The third line of each test case contains n integers b1,b2,…,bn the values of the cards in the dealer's hand from top to bottom.
It is guaranteed that the values of all cards are distinct.
Output : For each test case, output a single integer — the maximum number of points you can achieve.
*/
#include <iostream>
#include <vector>
// #include <deque>
#include<stack>
#include <algorithm>
using namespace std;
int game(vector<int> pl, vector<int>& dl){
    stack<int> p, d;
    for (int i = pl.size() - 1; i >= 0; i--) p.push(pl[i]);
    for (int i = dl.size() - 1; i >= 0; i--) d.push(dl[i]);
    int score = 0;
    for(int i = 0; i<dl.size();i++){
        int pc = p.top();
        int dc = d.top();
        if (pc > dc) {
            score++;
            p.pop();
        } else {
            d.pop();
        }
    }
    return score;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> pl(n), dl(n);
        for (int i = 0; i < n;i++){
            cin>>pl[i];
        }
        for (int i = 0; i < n;i++){
            cin>>dl[i];
        }
        int maxScore = game(pl, dl);
        for (int i = 0; i < n;i++){
            for (int j = i + 1; j < n;j++){
                swap(pl[i], pl[j]);
                maxScore = max(maxScore, game(pl, dl));
                swap(pl[i], pl[j]);
            }
        }
        cout<<maxScore<<endl;
    }
}

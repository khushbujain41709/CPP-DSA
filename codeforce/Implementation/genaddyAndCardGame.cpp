#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<char> card1(2);
    vector<vector<char>> cards(5, vector<char>(2)); 
    for(int i = 0; i<2; i++){
        cin>>card1[i];
    }
    for(int i = 0; i<5; i++){
        for(int j = 0; j<2; j++){
            cin>>cards[i][j];
        }
    }
    bool flag = false;
    for(int i = 0; i<5; i++){
        for(int j = 0; j<2; j++){
            if(cards[i][j] == card1[0] || cards[i][j] == card1[1]){
                cout<<"YES";
                flag = true;
                return 0;
            }
        }
    }
    if(flag == false) cout<<"NO";
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<int>> v(5, vector<int>(5,0));
    for(int i = 0; i<= 4; i++){
        for(int j = 0; j<= 4; j++){
            cin>>v[i][j];
        }
    }
    int count = 0;
    for(int i = 0; i<= 4; i++){
        for(int j = 0; j<= 4; j++){
            if(v[i][j] == 1){
                count += abs(2 - i);
                count += abs(2 - j);
            }
        }
    }
    cout<<count;
}
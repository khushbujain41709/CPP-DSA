#include <bits/stdc++.h>
using namespace std;
bool ans(vector<int>& vecna) {
    int n = vecna.size();
    int current_min_divisor = 1;
    for (int i = 0; i < n; i++) {
        int el = vecna[i];
        if (i == 0) continue; 
        bool found_divisor = false;
        for (int divisor = current_min_divisor + 1; divisor <= el; divisor++) {
            if (el % divisor == 0) {
                current_min_divisor = divisor;
                found_divisor = true;
                break;
            }
        }
        
        if (!found_divisor) return false;
    }
    
    return true;
}
int main() {
  int sizzi;
  cin>>sizzi;
  vector<int> vecna(sizzi);
  for(int i = 0;i<sizzi;i++){
    cin>>vecna[i];
  }
  if(ans(vecna)) cout<<"YES";
  else cout<<"NO";
}
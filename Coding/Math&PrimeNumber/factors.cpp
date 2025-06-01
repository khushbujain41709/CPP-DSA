// If n is divsible by i then i is factor of n.
#include<iostream>
#include<cmath>
using namespace std;
void factors(int num){
    for(int i = 1;i<= sqrt(num);i++){
        if(num% i == 0){
            cout<<i<<" ";
            if(i != sqrt(num)){
                cout<<num/i<<" ";
            }
        }
    }
}
// To print in increasing order
void factors2(int num){
    for(int i = 1;i<= sqrt(num);i++){ 
        if(num% i == 0){
            cout<<i<<" ";
        }
    }
    for(int i = sqrt(num);i > 0;i--){
        if(num% i == 0 && i != sqrt(num)){
            cout<<num/i<<" ";
        }
    }
}
int main(){
    factors(36);
    cout<<endl;
    factors2(36);
    return 0;
}
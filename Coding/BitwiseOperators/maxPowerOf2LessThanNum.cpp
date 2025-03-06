#include<iostream>
using namespace std;
// Method 1
int maxPow(int num){
    int i = 0;
    while(true){
        if((1<<(i)) > num){
            cout<<i-1<<"th Power of two that is : "<<(1<<(i-1))<<endl;
            return i -1;
        }
        i++;
    }
}
// Method 2 
// At end of opeartion num = num & (num-1), after removing set bits except one set bit, we get power of 2.
int maxPowOf2(int num){
    int temp = 0;
    while(num != 0){
        temp = num;
        num = num & (num-1);
    }
    return temp;
}
// Method 3 
// since this operation num = num | (num >> i); till 16 gives me all sets bits number(number having all one's) that is for 24 = 11000,  we get 31 = 11111 but we need 32/2 that is 16 in  answer.
int maxPowOf2new(int num){
    num = num | (num >> 1);
    num = num | (num >> 2);
    num = num | (num >> 4);
    num = num | (num >> 8);
    num = num | (num >> 16); // For 32 - bit number we do till 16.
    return (num + 1)/2; // or return (num+1)>>2;
}
int main(){
    int num;
    cin>>num;
    maxPow(num);
    cout<< maxPowOf2(num)<<endl;
    cout<<maxPowOf2new(num)<<endl;
    return 0;
}
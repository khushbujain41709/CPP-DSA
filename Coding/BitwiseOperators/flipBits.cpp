#include<iostream>
using namespace std;
/* Suppose number is
        110010110   // 406
        111111111   are all set bits number, now doing xor
        001101001   // 105 Hence flipped
*/
int flip(int num){
    int temp = num;
    num = num | (num >> 1);
    num = num | (num >> 2);
    num = num | (num >> 4);
    num = num | (num >> 8);
    num = num | (num >> 16); // For 32 - bit number we do till 16.
    num = temp ^ num;
    return num;
}
// -------------------------------------------------------------------------------
int maxPowOf2new(int num){
    num = num | (num >> 1);
    num = num | (num >> 2);
    num = num | (num >> 4);
    num = num | (num >> 8);
    num = num | (num >> 16); // For 32 - bit number we do till 16.
    return (num + 1)/2; // or return (num+1)>>2;
}
// Method 2 
/*
 
*/
int flip2(int num){
    int maxPow = maxPowOf2new(num);
    maxPow = (maxPow << 1);
    int allOnes = maxPow - 1;
    return (allOnes ^ num);
}
int main(){
    int num;
    cin>>num;
    cout<<flip(num)<<endl;
    cout<<flip2(num);
    return 0;
}
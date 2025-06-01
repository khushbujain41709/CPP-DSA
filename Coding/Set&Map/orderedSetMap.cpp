// set stores elements in increasing order or sorted manner and has unique elements.
// set insertion , deletion and searching operation takes O(log n) time.
#include<iostream>
#include<set>
#include<map>
using namespace std;
int main(){
    // set
    set<int> s;
    s.insert(5);
    s.insert(3);
    s.insert(7);
    s.insert(6);
    s.insert(4);
    for(int ele : s){
        cout<<ele<<" ";
    }
    cout<<endl;

    // map
    // In map, sorting is done on the basis of key
    // If keys are strings, then are sorted in lexicographical order.
    map<int , int> m;
    m[2] = 20;
    m[3] = 10;
    m[1] = 30;
    for(auto x : m){
        cout<<x.first<<" ";  // keys are sorted - 1 2 3
    }
    cout<<endl;
    for(auto x : m){
        cout<<x.second<<" ";  // freq are not sorted - 30 20 10
    }
    cout<<endl;
    return 0;
}
// TC of insertion in set - O(1)
// TC of searching in set - O(1) whereas it was O(log n) in Binary Search Tree and Binary Search in Array.
// TC of deletion in set - O(1)
// Set always stores unique elements
// Set size is unlimited
#include<iostream>
#include<unordered_set> // we are currently using these
#include<set>
using namespace std;
int main(){
    unordered_set<int> s;
    // storage of elements is done randomly 
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.insert(0);
    s.insert(7);
    s.insert(4);  // not unique

    cout<<s.size()<<endl;

    // For printing, displaying the elements of set, we use for each loop
    for(int ele : s){
        cout<<ele<<" "; // 7 0 5 1 2 3 4
    }
    cout<<endl;

    s.erase(1);
    // instead of data type, we can write auto
    for(auto ele : s){
        cout<<ele<<" "; // 7 0 5 1 2 3 4
    }
    cout<<endl;

    // To find an element exists or not in a set...
    // s.find() searches in set and if not found returns s.end() which is iterator next to the last value in set
    int target = 3;
    int target2 = 46;
    if(s.find(target) != s.end()){  // indicates target exists
        cout<<"Exists"<<endl;
    }
    else{
        cout<<"Does not exist"<<endl;
    }
    if(s.find(target2) == s.end()){  // indicates target does not exists
        cout<<"Does not exist"<<endl;
    }
    else{
        cout<<"Exists"<<endl;
    }
    return 0;
}
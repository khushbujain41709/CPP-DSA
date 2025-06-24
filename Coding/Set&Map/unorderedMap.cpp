 // unordered map insertion, deletion, searching all in O(1) time
 // unordered map size is unlimited
#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    // pair class
    pair<int, int> p;
    p.first = 1;
    p.second = 5;
    pair<string, int> pj;
    pj.first = "hii";
    pj.second = 46;
    cout<<pj.first<<" "<<pj.second<<endl;
    cout<<"-----------------------------------------------------------"<<endl;

    // unordered_map

    // Insertion
    unordered_map<string, int> mp;
    // mp.insert("hii , 46"); is incorrect. 
    // We can insert pairs only.
    pair<string, int> pjj;
    pjj.first = "hello";
    pjj.second = 230230;
    pair<string, int> pjjj;
    pjjj.first = "16th Sept";
    pjjj.second = 23115046;
    mp.insert(pj);
    mp.insert(pjj);
    mp.insert(pjjj);
    // we can also insert using this way :
    mp["khushbu"] = 47;
    mp["yo"] = 230193;

    // printing
    cout<<mp.size()<<endl;
    for(pair<string, int> p : mp){
        cout<<p.first<<" "<<p.second<<endl;
    }
    cout<<mp["hii"]<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
    // deletion
    mp.erase("yo"); // only use key to delete
    cout<<mp.size()<<endl;
    // instead of pair<string, int> p we can write auto
    for(auto p : mp){
        cout<<p.first<<" "<<p.second<<endl;
    }
    // to find element, we use key
    return 0;
}
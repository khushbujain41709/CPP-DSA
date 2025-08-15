// Leetcode - 100
#include<iostream>
#include<climits>
using namespace std;
class TreeNode{
    public :
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->value = val;
        this->left = NULL;
        this->right = NULL;
    }
};
bool isSameTree(TreeNode* p, TreeNode* q) {
    // base case
    if(p == NULL && q == NULL) return true; // if null comes together then true else false.
    if(p == NULL && q != NULL) return false;
    if(p != NULL && q == NULL) return false;
    if(p->value != q->value) return false;
    bool LSTans = isSameTree(p->left,q->left);
    if(LSTans == false) return false;
    bool RSTans = isSameTree(p->right,q->right);
    if(RSTans == false) return false;
    return true;
}
int main(){
    return 0;
}
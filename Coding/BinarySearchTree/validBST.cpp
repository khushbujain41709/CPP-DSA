// Leetcode - 98
#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public :
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

long long maxTree(TreeNode* root){
    if (root == NULL) return LLONG_MIN;
    return max((long long)(root->val), max(maxTree(root->left) , maxTree(root->right)));
}
long long minTree(TreeNode* root){
    if(root == NULL) return LLONG_MAX;
    return min((long long)(root->val), min(minTree(root->left) , minTree(root->right)));
}
bool isValidBST(TreeNode* root){
    if(root == NULL) return true;
    else if(root->left == NULL && root->right == NULL) return true;
    else if(maxTree(root->left) >= (long long)(root->val)){
        return false;
    }
    else if(minTree(root->right) <= (long long)(root->val)){
        return false;
    }
    return (isValidBST(root->left) && isValidBST(root->right));
}

void inorderTraversal(TreeNode* root, vector<int>& v){
    if(root == NULL) return;
    inorderTraversal(root->left,v);
    v.push_back(root->val);
    inorderTraversal(root->right, v);
}
bool isValidBST2(TreeNode* root){
    vector<int> v;
    if(root == NULL) return true;
    else if(root->left == NULL && root->right == NULL) return true;
    inorderTraversal(root,v);
    for(int i = 1;i<v.size();i++){
        if(v[i] <= v[i-1]) return false;
    }
    return true;
}

// Recommended Method
void inorderTraversal(TreeNode* root, TreeNode* &prev, bool &flag){
    if(root == NULL) return;
    inorderTraversal(root->left, prev, flag);
    if(prev != NULL){
        if(root->val <= prev->val){
            flag = false;
            return;
        }
    }
    prev = root;
    inorderTraversal(root->right, prev, flag);
}
bool isValidBST(TreeNode* root){
    if(root == NULL) return true;
    else if(root->left == NULL && root->right == NULL) return true;
    TreeNode* prev = NULL;
    bool flag = true;
    inorderTraversal(root, prev, flag);
    return flag;
}
int main(){

}
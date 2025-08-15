#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
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
// Method 1
int totalLevels(TreeNode* root){
    if(root == NULL) return 0;
    return (1 + max(totalLevels(root->left) , totalLevels(root->right)));
}
void LevelOrder(TreeNode* root, int level, vector<int>& vec, int curr){
    if(root == NULL) return;
    if(level == curr){
        vec.push_back(root->val);
    }
    LevelOrder(root->left,level,vec,curr+1);
    LevelOrder(root->right,level,vec,curr+1);
}
vector<int> rightSideView(TreeNode* root){
    vector<int> vec;
    int levels = totalLevels(root);
    vector<int> ans(levels);
    for(int i = 0;i<levels;i++){
        LevelOrder(root,i,vec,0);
        ans[i] = vec[vec.size()-1];
        vec.clear();
    }
    return ans;
}
// Method 2
int totalLevels(TreeNode* root){
    if(root == NULL) return 0;
    return (1 + max(totalLevels(root->left) , totalLevels(root->right)));
}
void preOrder(TreeNode* root, int level, vector<int>& vec){
    if(root == NULL) return;
    vec[level] = root->val; // It keeps on changing.
    preOrder(root->left,level+1,vec);
    preOrder(root->right,level+1,vec);
}
vector<int> rightSideView(TreeNode* root){
    int levels = totalLevels(root);
    vector<int> ans(levels);
    preOrder(root, 0, ans);
    return ans;
}
int main(){
    TreeNode* a = new TreeNode(1);
    TreeNode* b = new TreeNode(2);
    TreeNode* c = new TreeNode(3);
    TreeNode* d = new TreeNode(4);
    TreeNode* e = new TreeNode(5);
    TreeNode* f = new TreeNode(6);
    TreeNode* g = new TreeNode(7);
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;
    return 0;
}
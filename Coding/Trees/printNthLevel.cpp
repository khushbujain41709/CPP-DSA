#include<iostream>
#include<vector>
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
void nthLevel(TreeNode* root,int curr, int level){
    if(root == NULL){
        return ;
    }
    if(level == curr){
        cout<<root->val<<" ";
        return; // for optimization
    } 
    nthLevel(root->left, curr + 1, level);
    nthLevel(root->right,curr + 1, level);
}
void nthLevelRev(TreeNode* root,int curr, int level){
    if(root == NULL){
        return ;
    }
    if(level == curr){
        cout<<root->val<<" ";
        return; // for optimization
    } 
    nthLevelRev(root->right,curr + 1, level);
    nthLevelRev(root->left, curr + 1, level);
}
int levelOfTree(TreeNode* root){
    if(root == NULL) return 0;
    return (1 + max(levelOfTree(root->left) , levelOfTree(root->right)));
}
void levelOrderTraversal(TreeNode* root){
    int n = levelOfTree(root);
    for(int i = 0;i<n;i++){
        nthLevel(root,0,i);
        cout<<endl;
    }
}
void levelOrderTraversalRev(TreeNode* root){
    int n = levelOfTree(root);
    for(int i = 0;i<n;i++){
        nthLevelRev(root,0,i);
        cout<<endl;
    }
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

    nthLevel(a,0,2);
    cout<<endl;
    cout<<endl;
    levelOrderTraversal(a);
    cout<<endl;
    levelOrderTraversalRev(a);
    return 0;
}
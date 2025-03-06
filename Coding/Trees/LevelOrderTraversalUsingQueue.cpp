// Known as BFS(Breadth First Search)
// More Optimized
// Leetcode 102
#include<iostream>
#include<vector>
#include<queue>
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
int level(TreeNode* root){
    if(root == NULL) return 0;
    return (1 + max(level(root->left) , level(root->right)));
}
void LevelOrderQueue(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* temp = q.front();
        if(temp->left != NULL){
            q.push(temp->left);
        }
        if(temp->right != NULL){
            q.push(temp->right);
        }
        q.pop();
        cout<<temp->val<<" ";
    }
}
void LevelOrderQueueRev(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* temp = q.front();
        if(temp->right != NULL){
            q.push(temp->right);
        }
        if(temp->left != NULL){
            q.push(temp->left);
        }
        q.pop();
        cout<<temp->val<<" ";
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

    LevelOrderQueue(a);
    cout<<endl;
    LevelOrderQueueRev(a);
    cout<<endl;
    return 0;
}
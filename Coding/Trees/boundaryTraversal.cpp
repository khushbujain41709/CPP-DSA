#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
// Boundary Traversal includes -
// 1) Left Boundary(excluding leaf nodes)
// 2) Leaf nodes(left to right)
// 3) Right Boundary(excluding leaf nodes and print in reverse order)
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
void printLeafNodes(TreeNode* root, vector<int>& ans){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->val);
    } 
    printLeafNodes(root->left,ans);
    printLeafNodes(root->right,ans);
}
void printLeftBoundary(TreeNode* root, vector<int>& ans){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL) return;
    ans.push_back(root->val);
    if(root->left){
        printLeftBoundary(root->left, ans);
    }
    else printLeftBoundary(root->right, ans);
}
void printRightBoundary(TreeNode* root, vector<int>& ans){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL) return;
    if(root->right){
        printRightBoundary(root->right, ans);
    }
    else printRightBoundary(root->left, ans);
    ans.push_back(root->val);
}
vector<int> constructBoundary(TreeNode* root){
    vector<int> ans;
    printLeftBoundary(root,ans);
    printLeafNodes(root, ans);
    printRightBoundary(root->right,ans);
    return ans;
}
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->right->left = new TreeNode(7);
    root->left->right->left->right = new TreeNode(10);
    root->right->right->left = new TreeNode(8);
    root->right->right->right = new TreeNode(9);
    root->right->right->right->left = new TreeNode(11);
    vector<int> boundary = constructBoundary(root);
    cout << "Boundary Traversal : ";
    for (int val : boundary){
        cout << val << " ";
    }
    return 0;
}
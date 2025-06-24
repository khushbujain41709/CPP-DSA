#include<iostream>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value){
        val = value;
        left = NULL;
        right = NULL;
    }
};

TreeNode* insertion(TreeNode* root, int value){
    if(root == NULL){
        return new TreeNode(value);
    }
    else if((root->val) > value){
        if(root->left == NULL){
            TreeNode* temp = new TreeNode(value);
            root->left = temp;
        }
        else{
            insertion(root->left, value);
        }
    }
    else{
        if(root->right == NULL){
            TreeNode* temp = new TreeNode(value);
            root->right = temp;
        }
        else{
            insertion(root->right, value);
        }
    }
    return root;
}

TreeNode* searchBST(TreeNode* root, int key){
    if(root == NULL) return NULL;
    else if(root->val == key) return root;
    else if(root->val > key){
        return searchBST(root->left , key);
    }
    else{
        return searchBST(root->right, key);
    }
}

void preOrderTraversal(TreeNode* root){
    cout<<root->val<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

TreeNode* deletion(TreeNode* root, int key){
}
int main(){
    return 0;
}
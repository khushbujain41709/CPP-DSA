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
vector<int> PreOrderIterative(TreeNode* root){
    stack<TreeNode*> st;
    vector<int> ans;
    st.push(root);
    while(!st.empty()){
        TreeNode* temp = st.top();
        st.pop();
        ans.push_back(temp->val);
        if(temp->right != NULL){ // As stack follows LIFO, we are inserting right first then left so that top of stack is left side.
            st.push(temp->right);
        }
        if(temp->left != NULL){
            st.push(temp->left);
        }
    }
    return ans;
}
vector<int> postorderTraversal(TreeNode* root) {
    if(root == NULL) return {};
    vector<int> ans;
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
        TreeNode* temp = st.top();
        st.pop();
        ans.push_back(temp->val);
        if(temp -> left != NULL){   // As stack follows LIFO, we are inserting left first then right so that top of stack is right side.
            st.push(temp->left);
        }
        if(temp -> right != NULL){
            st.push(temp->right);
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
vector<int> inOrderTraversal(TreeNode* root){
    if(root == NULL) return {};
    vector<int> ans;
    stack<TreeNode*> st;
    TreeNode* node = root;
    while(node!= NULL || !st.empty()){
        if(node != NULL){
            st.push(node);
            node = node->left;
        }
        else{
            TreeNode* temp = st.top();
            st.pop();
            ans.push_back(temp->val);
            node = temp ->right;
        }
    }
    return ans;
}
int main(){
    return 0;
}
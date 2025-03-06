#include<iostream>
#include<vector>
#include<queue>
#include<climits>
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
// {3,9,20,null,null,15,7}
// Here 3 is root i = 1 at 9 and j = 2 at 20 then i += 2 so i = 3 at null and j = 4 at null again i = 5 at 15 and j = 6 at 7.
/*
             3
           /   \
          9    20
         / \  /  \
        n   n 15  7 
*/
TreeNode* constructBT(vector<int>& v){
    int i = 1; // v[0] is root and then i represent left side and j right so i like v[1] and j is like v[2]
    int j = 2; 
    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(v[0]);
    q.push(root);
    while(!q.empty() && i < v.size()){
        TreeNode* temp = q.front();
        q.pop();
        TreeNode* l;  // left side
        TreeNode* r;  // right side
        if(v[i] != INT_MIN){
            l = new TreeNode(v[i]);
            temp->left = l;
        }
        else{
            l = NULL;
        }
        if(j != v.size() && v[j] != INT_MIN){ // as something j is out of vector and i is at last element. Sometimes, last null is omited.
            r = new TreeNode(v[j]);
            temp->right = r;
        }
        else{
            r = NULL;
        }
        if(l != NULL) q.push(l);
        if(r != NULL) q.push(r);
        i += 2;
        j += 2; 
    }
    return root;
}
void levelOrderQueue(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();
        if(temp->left != NULL){
            q.push(temp->left);
        }
        if(temp->right != NULL){
            q.push(temp->right);
        }
        cout<<temp->val<<" ";
    }
}
int main(){
    //vector<int> v = {3,9,20,null,null,15,7}; But as null is not an integer we use INT_MIN in place of null
    vector<int> v = {3,9,20,INT_MIN,INT_MIN,15,7};
    TreeNode* root = constructBT(v);
    levelOrderQueue(root);

    cout<<endl;

    vector<int> vec = {1,2,3,4,5,INT_MIN,6,INT_MIN,INT_MIN,7,8,9};
    TreeNode* root2 = constructBT(vec);
    levelOrderQueue(root2);
    return 0;
}
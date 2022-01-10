/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        int index=0;
        return build(preorder,inorder,0,n-1,index);
    }
    
    TreeNode* build(vector<int> &p, vector<int> &in, int i, int j, int &num){
        if(j<i){ return nullptr; }
        TreeNode* root=new TreeNode(p[num++]);
        int k=find(begin(in),end(in),root->val)-begin(in);
        root->left = build(p,in,i,k-1,num);
        root->right = build(p,in,k+1,j,num);
        return root;
    }
};
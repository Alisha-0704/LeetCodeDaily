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
    vector<int>res;
    void fin(TreeNode* root){
        if(root==NULL)
            return ;
            if(root->left)
            fin(root->left);
            res.push_back(root->val);
            if(root->right)
            fin(root->right);
       
       
        return ;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL && root2==NULL)
            return {};

        fin(root1);
        fin(root2);
        sort(res.begin(),res.end());
        return res;
        
    }
};
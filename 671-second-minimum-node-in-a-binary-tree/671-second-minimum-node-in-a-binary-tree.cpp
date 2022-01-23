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
    long ans=LONG_MAX;
    int mini;
    void dfs(TreeNode* root){
        if(!root)
           return;
        if(mini<root->val && root->val<ans)
            ans=root->val;
        else
            if(mini==root->val){
                dfs(root->left);
                dfs(root->right);
            }
        return;
    }
    int findSecondMinimumValue(TreeNode* root) {
        mini=root->val;
        dfs(root);
        return ans<LONG_MAX?(int)ans:-1;
    }
};
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
     int sum=0;
    void dfs(TreeNode* root,int num){
        if(!root->left && !root->right){
            sum=sum+num*2+root->val;
            //cout<<sum<<" "<<endl;
            return;
        }
        if(root->left){
           dfs(root->left,num<<1|root->val);
        }

        if(root->right){
           dfs(root->right,num<<1|root->val);
        }
        return ;
    }
    int sumRootToLeaf(TreeNode* root) {
        if(!root)
            return 0;
       
        dfs(root,0);
        
        return sum;
    }
};
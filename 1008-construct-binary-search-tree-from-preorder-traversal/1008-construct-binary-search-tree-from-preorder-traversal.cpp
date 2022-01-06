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

    TreeNode* bstFromPreorder(vector<int>&p) {
        if(p.size()==0)
            return NULL;
        
        TreeNode* root = new TreeNode(p[0]);
        int i=1;
        for(; i<p.size(); i++){
            if(p[i] > p[0]) break;
        }
        vector<int> left = vector<int>(p.begin()+1, p.begin()+i);
        vector<int> right = vector<int>(p.begin()+i, p.end());
        root->left=bstFromPreorder(left); 
        root->right=bstFromPreorder(right); 
        return root;
    }
};
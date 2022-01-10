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
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int index=inorder.size()-1;
        return tree(postorder, inorder, 0, inorder.size()-1, index);
    }
    TreeNode* tree(vector<int> &p, vector<int> &in, int i, int j, int &index){
        if(i>j) return NULL;
        TreeNode *root = new TreeNode(p[index--]);
        int k = find(in.begin(), in.end(), root->val) - in.begin();
        root->right = tree(p, in, k+1, j, index);
        root->left = tree(p, in, i, k-1, index);
        return root;
    }
    

};
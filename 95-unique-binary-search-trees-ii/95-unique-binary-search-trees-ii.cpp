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
    vector<TreeNode*>helper(int i,int j){
        vector<TreeNode*> res;
        TreeNode* temp=NULL;
        if(i>j){
            res.push_back(temp);
            return res; 
        }
        if(i==j){
            temp= new TreeNode(i);
            res.push_back(temp);
            return res;
        }
        
        for(int k=i;k<=j;k++){
            for(auto &l:helper(i,k-1)){
                for(auto &r: helper(k+1,j)){
                    temp=new TreeNode(k);
                    temp->left=l;
                    temp->right=r;
                    res.push_back(temp);
                }
            }
        }
        return res; 
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n==0 )
            return {};
     
        return helper(1,n);
    }
};
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
    int findBottomLeftValue(TreeNode* root) {
        if(!root)
            return 0;
        
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        vector<pair<int,int>>res;
        res.push_back(make_pair(root->val,level));
        while(!q.empty()){
            int s=q.size();
            level++;
            while(s--){
                
                TreeNode* a=q.front();
                
                q.pop();
                if(a->left)
                {q.push(a->left);
                 res.push_back(make_pair(a->left->val,level));}
                if(a->right)
                {q.push(a->right);
              res.push_back(make_pair(a->right->val,level));}
            }
        }
        int k=res[res.size()-1].second;
        for(int i=0;i<res.size();i++)
        {   //cout<<res[i].first<<res[i].second<<endl;
            if(res[i].second==k)
                return res[i].first;}
        return 0;
    }
};
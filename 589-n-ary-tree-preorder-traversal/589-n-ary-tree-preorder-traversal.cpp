class Solution {
public:
    void preorderHelper(Node* node, vector<int> &results){
        //Add it to the results array
        results.push_back(node->val);
        //Recursilvely call on children
        for(Node* child : node->children){
            preorderHelper(child, results);
        }
    }
    
    vector<int> preorder(Node* root) {
        vector<int> results;
        if(root==nullptr){
            return results;
        }
        preorderHelper(root, results);
        return results;
    }
};
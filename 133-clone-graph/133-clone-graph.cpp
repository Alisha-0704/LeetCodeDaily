/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
Node* cloneGraph(Node* node) {
        if(node==NULL){
            return NULL;
        }
        map<Node*,Node*>m;
        queue<Node*>q;
        q.push(node);
        vector<int>v(101,0);
        while(!q.empty()){
            Node*temp=q.front();
            q.pop();
            m[temp]=new Node(temp->val); // created new node and stored in map with corresponding node in original graph 
            for(auto it:temp->neighbors){
                if(!v[it->val]){
                    q.push(it);
                    v[it->val]=true;
                }
            }
        }
        for(auto it:m){
            for(auto i:it.first->neighbors){
                m[it.first]->neighbors.push_back(m[i]);    // making the connection in nodes
            }
        }
        return m[node];
    }
};
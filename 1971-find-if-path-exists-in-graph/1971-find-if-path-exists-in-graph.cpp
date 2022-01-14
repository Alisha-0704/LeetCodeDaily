class Solution {
public:
    
   
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        
        map<int,vector<int>>adj;
        if(edges.size()==0 && start==0 && end==0)
            return true;
        for(int i=0;i<edges.size();i++){
           adj[edges[i][0]].push_back(edges[i][1]);
           adj[edges[i][1]].push_back(edges[i][0]); 
        }
        queue<int>q;
        q.push(start);
        vector<int>vis(n,0);
        while(!q.empty()){
            
            
            int size=q.size();
            
            while(size--){
                
                auto curr=q.front(); q.pop();
                if(vis[curr]) break;
                vis[curr]=1;
                if(curr==end){
                    return true;
                }
                
                for(auto &it:adj[curr]){
                    
                    if(!vis[it]){
                        q.push(it);
                    }
                }
                
            }
        }
        
        return false;
        
       
    }
};
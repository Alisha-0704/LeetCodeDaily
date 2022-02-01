class Solution {
public:
    bool dfs(int idx,vector<int>&color,vector<vector<int>>&graph){
        if(color[idx]>0)
            return color[idx]==2;
        color[idx]=1;
        
        for(auto & nei:graph[idx]){
            if(color[idx]==2)
                continue;
            if(color[nei]==1 || !dfs(nei,color,graph))
                return false;
        }
        color[idx]=2;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,0);
        
        vector<int>ans;
        
        for(int i=0;i<n;i++){
            if(dfs(i,color,graph))
                ans.push_back(i);
        }
        return ans;
    }
};
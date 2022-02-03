class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n= recipes.size();
        unordered_map<string,vector<string>> graph;
        unordered_map<string,int> indegree;
       
        for(int i=0;i<n;i++){
            for(auto &it: ingredients[i]){
                graph[it].push_back(recipes[i]);
                indegree[recipes[i]]++;
            }
        }
    
    queue<string> Q;vector<string> ans;
        for(auto &it: supplies)
            Q.push(it);
        
        while(!Q.empty()){
            int size = Q.size();
            while(size--){
                string current = Q.front();
                    Q.pop();
                for(auto &it: graph[current]){
                    if(--indegree[it]==0)
                    Q.push(it),ans.push_back(it);    
                }
                  
            }
                 
        }
    return ans;
    }
};
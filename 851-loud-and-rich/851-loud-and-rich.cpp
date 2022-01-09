class Solution {
public:

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
    int n = quiet.size();
    vector<vector<int>> graph(n);
    for(auto i : richer)
        graph[i[1]].push_back(i[0]);
    
    vector<bool> visited(n, false);
    vector<int> ans(n);
    for(int i = 0; i < n; i++)
        if(!visited[i])
            dfs(i, visited, ans, quiet, graph);
    
    return ans;
}

int dfs(int i, vector<bool> &visited, vector<int> &ans, vector<int> &quiet, vector<vector<int>> &graph)
{
    if(visited[i])
        return ans[i];
    
    int tmp = i;
    for(auto j : graph[i])
    {
        int tmp2 = dfs(j, visited, ans, quiet, graph);
        if(quiet[tmp] > quiet[tmp2])
            tmp = tmp2;
    }
       
    visited[i] = true;
    return ans[i] = tmp;
}
};
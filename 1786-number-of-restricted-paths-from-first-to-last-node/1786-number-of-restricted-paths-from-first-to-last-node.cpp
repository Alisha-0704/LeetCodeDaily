#define MOD 1000000007
class Solution
{
    public:
    void dfs(unordered_map<int,vector<pair<int,int>>>& graph, int start, int n, vector<long long int>& distance, vector<int>& paths)
    {
        stack<int>st;
        st.push(start);
        vector<int>visited(n+1,0);
        
        while(!st.empty())
        {
            int u=st.top();
            if(visited[u]==0)
            {
                visited[u]=1;
                for(auto p:graph[u])
                {
                    int v=p.first,w=p.second;
                    if(distance[v]<distance[u])
                        st.push(v);
                }
            }
            else if(visited[u]==1)
            {
                visited[u]=2;
                st.pop();
                if(paths[u]==-1)
                {
                    paths[u]=0;
                    for(auto p:graph[u])
                    {
                        int v=p.first,w=p.second;
                        if(distance[v]<distance[u])
                            paths[u]=(paths[u]+paths[v])%MOD;
                    }
                }
            }
            else
                st.pop();
        }
    }
    void djikstra(unordered_map<int,vector<pair<int,int>>>& graph, int start, vector<long long int>& distance)
    {
        priority_queue<pair<long long int,int>,vector<pair<long long int,int>>,greater<pair<long long int,int>>>pq;
        
        pq.push({0,start});
        distance[start]=0;
        
        while(!pq.empty())
        {
            long long int du=pq.top().first;
            int u=pq.top().second;
            pq.pop();
            
            for(auto p:graph[u])
            {
                int v=p.first,dv=p.second;
                long long int dist=distance[u]+dv;
                if(dist<distance[v])
                {
                    distance[v]=dist;
                    pq.push({distance[v],v});
                }
            }
        }
    }
    int countRestrictedPaths(int n, vector<vector<int>>& edges)
    {
        unordered_map<int,vector<pair<int,int>>>graph;
        
        for(auto edge:edges)
        {
            graph[edge[0]].push_back({edge[1],edge[2]});
            graph[edge[1]].push_back({edge[0],edge[2]});
        }
        
        vector<long long int>distance(n+1,LLONG_MAX);
        djikstra(graph,n,distance);

        vector<int>paths(n+1,-1);
        paths[n]=1;
        dfs(graph,1,n,distance,paths);
        
        return paths[1];
    }
};
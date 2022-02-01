class Solution 
{
    public:
    void floydWarshall(vector<vector<bool>>& matrix, int n)
    {
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(i==j || i==k || j==k)
                        continue;
                    matrix[i][j]=(matrix[i][j]||(matrix[i][k]&&matrix[k][j]));
                }
            }
        }
    }        
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries)
    {
        
        vector<vector<bool>>matrix(numCourses,vector<bool>(numCourses,false));
    
        for(auto edge:prerequisites)
            matrix[edge[0]][edge[1]]=true;

        floydWarshall(matrix,numCourses);
        
        int n=queries.size();
        vector<bool>ans(n);
        
        for(int i=0;i<n;i++)
            ans[i]=matrix[queries[i][0]][queries[i][1]];
        
        return ans;
    }
};
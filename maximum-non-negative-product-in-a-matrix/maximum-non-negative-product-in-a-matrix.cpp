#define inf 100000000
#define mod 1000000007

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
                int m = grid.size(),n = grid[0].size();
        vector<vector<long long int>>pos(m,vector<long long int>(n,-inf)),neg(m,vector<long long int>(n,inf));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i-1>=0 )
                {
                    if(grid[i][j]>=0 && pos[i-1][j]!=-inf) pos[i][j] = max(pos[i][j],pos[i-1][j]*grid[i][j]);
                    if(grid[i][j]>=0 && neg[i-1][j]!=inf) neg[i][j] = min(neg[i][j],neg[i-1][j]*grid[i][j]);
                    if(grid[i][j]<=0 && neg[i-1][j]!=inf) pos[i][j] = max(pos[i][j],neg[i-1][j]*grid[i][j]);
                    if(grid[i][j]<=0 && pos[i-1][j]!=-inf) neg[i][j] = min(neg[i][j],pos[i-1][j]*grid[i][j]);
                }
                if(j-1>=0 )
                {
                    if(grid[i][j]>=0 && pos[i][j-1]!=-inf) pos[i][j] = max(pos[i][j],pos[i][j-1]*grid[i][j]);
                    if(grid[i][j]>=0 && neg[i][j-1]!=inf) neg[i][j] = min(neg[i][j],neg[i][j-1]*grid[i][j]);
                    if(grid[i][j]<=0 && neg[i][j-1]!=inf) pos[i][j] = max(pos[i][j],neg[i][j-1]*grid[i][j]);
                    if(grid[i][j]<=0 && pos[i][j-1]!=-inf) neg[i][j] = min(neg[i][j],pos[i][j-1]*grid[i][j]);
                }
                if(i-1<0 && j-1<0)
                {
                    if(grid[i][j]>=0) pos[i][j] = grid[i][j];
                    if(grid[i][j]<=0) neg[i][j] = grid[i][j];
                }
            }
        }
        pos[m-1][n-1] %= mod;
        return pos[m-1][n-1]==-inf?-1:pos[m-1][n-1];
    }
};
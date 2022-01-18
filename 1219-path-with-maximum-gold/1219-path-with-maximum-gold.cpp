class Solution {
public:
    int ans =0;
    
    int dfs(vector<vector<int>>& grid, int i, int j, int r, int c){
        if(i < 0 || j < 0 || i>=r || j>=c || grid[i][j] == 0 ) return 0;
       
        int x = grid[i][j];
        grid[i][j] = 0; // marking visited so that we cannot come back to this cell again
        
        // we have 4 options to choose and
        // we will return the option which is giving the max golds
        int op1 = dfs(grid, i+1,j, r,c);
        int op2 = dfs(grid, i, j+1, r,c);
        int op3 = dfs(grid, i-1,j,r,c);
        int op4 = dfs(grid,i,j-1,r,c);
        
        grid[i][j] = x;   // backtrack
        int mx = max(op1,max(op2,max(op3,op4)));
        
        return mx + x;
        
        
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        
           int r = grid.size();
           int c = grid[0].size();
        
           for(int i = 0; i<r; i++){
               for(int j = 0; j<c; j++){
                     if(grid[i][j]!=0){          // skips cells having 0 golds        
                        ans = max(ans, dfs(grid,i,j,r,c));
                     }
               }
           }
        return ans;
    }
};
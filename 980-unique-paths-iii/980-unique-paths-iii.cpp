class Solution {
public:
        int uniquePathsIII(vector<vector<int>>& grid) {
        int zero=0,x,y;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!grid[i][j]) zero++;
                else if(grid[i][j]==1) {
                    x=i;y=j; // this is the starting point of robot
                }  
            }
        }
        return dfs(grid,x,y,zero);
    }
    int dfs(vector<vector<int>>&grid,int x,int y,int zero){
        if(x<0 or x>grid.size()-1 or y<0 or y>=grid[0].size() or grid[x][y]==-1) return 0;
        if(grid[x][y]==2) return zero==-1; // 2 is the ending point so we are checking if zeros are -1 or not 
		// if zeros are -1, it means we have traveled all the grids (not 0 because we are also using start point as zero
        grid[x][y]=-1; // marking it as visited or as obstacle
        zero--; 
        int sum=dfs(grid,x+1,y,zero)+dfs(grid,x-1,y,zero)+dfs(grid,x,y-1,zero)+dfs(grid,x,y+1,zero);
        zero++; // backtrack process
        grid[x][y]=0;
        return sum;
    }
};
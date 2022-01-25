class Solution {
public:
    int sol_count = 0;
    bool canPlaceQueen(vector<vector<int>>& matrix, int i, int j, int n){
        //Column check
        for(int col = 0;col<i;col++){
            if(matrix[col][j] == 1){
                return false;
            }
        }
        //Left diagonal check
        int row = i;
        int col = j;
        while(row >= 0 and col >= 0){
            if(matrix[row][col] == 1){
                return false;
            }
            row--;
            col--;
        }

        //Right diagonal check
        row = i;
        col = j;
        while(row >= 0 and col < n){
            if(matrix[row][col] == 1){
                return false;
            }
            row--;
            col++;
        }
        return true;
    }
     void NQueens(vector<vector<int>>& matrix, int i, int n){
        //Base Cases
        if(i == n){
            sol_count++;
        }
        
        //Recursive Cases
        for(int j=0;j<n;j++){
            if(canPlaceQueen(matrix, i, j, n)){
                matrix[i][j] = 1;
                NQueens(matrix, i+1, n);
                matrix[i][j] = 0;
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matrix[i][j] = 0;
            }
        }
        NQueens(matrix, 0, n);
        return sol_count;
        
    }
};
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        set<int>rvals;
        set<int>cvals;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==0){
                   rvals.insert(i);
                    cvals.insert(j);
                }
            }
        }
        
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(rvals.count(i) || cvals.count(j)){
                    matrix[i][j]=0;
                }
            }
        }
        return ;
    }
};
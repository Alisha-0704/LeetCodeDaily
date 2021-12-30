class Solution {
public:
    
    int helper(vector<int>& piles,int left,int right,vector<vector<int>>&dp){
        if(left>=right)
            return 0;
        if(dp[left][right]!=-1)
            return dp[left][right];
        int choosel=piles[left]+min(helper(piles,left+2,right,dp),helper(piles,left,right-1,dp));
        
        int chooser=piles[right]+min(helper(piles,left+1,right,dp),helper(piles,left,right-2,dp));
        
        return dp[left][right]=max(choosel,chooser);
    }
    bool stoneGame(vector<int>& piles) {
        if(piles.size()==0)
            return false;
        int sumval=0;
        vector<vector<int>>dp(piles.size()+1,vector<int>(piles.size()+1,-1));
        for (int i=0;i<piles.size();i++){
            sumval+=piles[i];
        }
        return helper(piles,0, piles.size()-1,dp)>sumval/2?true:false;
    }
};
class Solution {
public:

int mctFromLeafValues(vector<int>& arr) {
        int n=arr.size();
        vector<vector<pair<int,int>>> dp(n,vector<pair<int,int>>(n)); //pair is cost,max
        for(int i=0;i<n;i++)
            dp[i][i]={0,arr[i]};
        for(int l=2;l<=n;l++)
        {
            for(int i=0;i<n-l+1;i++)
            {
                int j=i+l-1;
                if(l==2)
                    dp[i][j]={arr[i]*arr[j],max(arr[i],arr[j])};
                else
                {
                    dp[i][j].second=max(arr[j],dp[i][j-1].second);
                    int res=INT_MAX;
                    for(int k=i;k<j;k++)
                    {
                        res=min(res,dp[i][k].first+dp[k+1][j].first+dp[i][k].second*dp[k+1][j].second);
                    }
                    dp[i][j].first=res;
                }
                    
             
            }
        }
  
        return dp[0][n-1].first;
    }
};
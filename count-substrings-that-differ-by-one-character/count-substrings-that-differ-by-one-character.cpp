class Solution {
public:
    int countSubstrings(string s, string t) {
        if(s.length()==0 && t.length()==0)
            return 1;
        
        if(s.length()==0 || t.length()==0)
            return 0;
        int n=s.length();
        int m=t.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        vector<vector<int>>dp1(n+1,vector<int>(m+1,0));
        int ans=0;
        for(int i=1;i<=s.length();i++){
            for(int j=1;j<=t.length();j++){
                if(s[i-1]==t[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                    dp1[i][j]=dp1[i-1][j-1];
                }
                else
                    dp1[i][j]=1+dp[i-1][j-1];
                ans+=dp1[i][j];
            }
        }
        return ans;
    }
};
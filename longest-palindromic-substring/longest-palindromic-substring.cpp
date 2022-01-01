class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()<=1)
            return s;
        
        vector<vector<int>>dp(s.length(),vector<int>(s.length(),0));
        int n = s.length();
       
        int length = 0 , end = -1; 
        for(int i=s.length();i>=0;i--){
            for(int j=i;j<s.length();j++){
                if(i==j)
                    dp[i][j]=1;
                else
                if(s[i]==s[j])
                {
                   int ans = 2;
                    if(i < s.length()-1 && j > i+1){
                        if(dp[i+1][j-1]){
                            ans += dp[i+1][j-1];
                        }
                        else{
                            ans = 0;
                        }
                }
                    dp[i][j] = ans;
              
            }
                else{
                    dp[i][j] = 0;
                }
                if(length < dp[i][j]){
                    length = dp[i][j]; // update dp state with its max value
                    end = j; // ending index of longest palindromic substring so far.
                }
            }
        }
        // finally our longest palindromic substring will start from (end-length-1) and its ending index is end
        return s.substr(end-length+1 , length);  
    }
};
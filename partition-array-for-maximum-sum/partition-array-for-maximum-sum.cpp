class Solution {
public:
    int helper(vector<int>& arr, int k,vector<int>&dp,int idx){
        if(idx>=arr.size())
            return 0;
        if(dp[idx]!=-1)
            return dp[idx];
        
       int ans=0;
        int n=arr.size();
        int l=min(n,idx+k);
        
        for(int i=idx;i< l;i++){
            int maximval=-1;
            int sum=0;
            
            for(int j=idx;j<=i;j++){
                maximval=max(maximval,arr[j]);
            }
            sum+=maximval*(i-idx+1);
            //cout<<"sumj"<<sum<<endl;
            sum+=helper(arr,k,dp,i+1);
            //cout<<"sumrecur"<<sum<<endl;
            ans=max(ans,sum);
        }
        return dp[idx]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        if(arr.size()==0)
            return 0;
        
        vector<int>dp(arr.size()+1,-1);
        return helper(arr,k,dp,0);
        
    }
};
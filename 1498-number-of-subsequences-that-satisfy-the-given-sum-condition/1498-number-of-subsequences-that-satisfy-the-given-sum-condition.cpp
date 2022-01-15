class Solution {
public:
int calpow(int a,int b)
{
if(b==0)return 1;

    int res=calpow(a,b/2);
    
    if(b%2==0)
    {
        res=res*res;
    }
    else
    {
        res=res*a*res;
    }
    return res;
}

int numSubseq(vector<int>& nums, int target) 
{
    int mod=1000000007;
    int n=nums.size();
    int i=0,j=n-1;
    int ans=0;
    
     vector<int> pow(n,1);

     for(int i=1; i<n; i++)
     {
           pow[i] = (pow[i-1] * 2) % mod;   
     }
    
    sort(nums.begin(),nums.end());
    
    while(i<=j)
    {
        if(nums[i]+nums[j]>target)j--;
        
        else
        {
            ans=(ans+pow[j-i])%mod;
            i++;
        }
    }
    return ans;
}
};
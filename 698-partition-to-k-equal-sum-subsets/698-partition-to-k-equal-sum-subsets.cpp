class Solution {
public:
     vector<bool> visited;
    bool helper(int idx,int csum,int t,int k,vector<int>nums){
        if(k==1)
            return true;
        if(csum==t)
            return helper(0,0,t,k-1,nums);

        for(int i=idx; i<nums.size(); i++){
            if(csum+nums[i]>t || visited[i])
            continue;
            csum+=nums[i];
            visited[i]=true;
            if(helper(i+1,csum,t,k,nums))     
                return true;
            csum-=nums[i];
            visited[i]=false;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
          visited.assign(nums.size(),false);
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%k!=0)
            return false;
        sort(nums.begin(),nums.end());
        return helper(0,0,sum/k,k,nums);
    }
};
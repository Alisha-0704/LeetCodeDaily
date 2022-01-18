class Solution {
public:
    int find_maxor(vector<int>&nums)
    {
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            ans=ans|nums[i];
        }
        return ans;
    }
    int maxim=0;
    void bt(vector<int>&nums,int start,int end,int res,int mor){
        if(start>end){
           if(res==mor)
               maxim++;
            return;}
        bt(nums,start+1,end,res,mor);
        res=res | nums[start];
        bt(nums,start+1,end,res,mor);
            
        
        return ;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        if(nums.size()==1)
            return 1;
        int mor=find_maxor(nums);
        bt(nums,0,nums.size()-1,0,mor);
        
        return maxim;
    }
};
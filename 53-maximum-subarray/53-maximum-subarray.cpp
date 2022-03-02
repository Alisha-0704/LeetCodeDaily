class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int currmax=nums[0];
        int finmax=nums[0];
        for(int i=1;i<nums.size();i++){
            currmax=max(nums[i],nums[i]+currmax);
            finmax=max(currmax,finmax);
        }
        return finmax;
    }
};
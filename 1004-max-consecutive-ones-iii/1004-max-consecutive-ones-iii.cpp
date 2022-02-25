class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start=0;
        int zeros=0;
        int ans=INT_MIN;
        for(int end=0;end<nums.size();end++)
        {
            if(nums[end]==0)
                zeros++;
            while(zeros>k)
            {
                if(nums[start]==0)
                    zeros--;
                start++;
            }
            ans=max(ans,end-start+1);
        }
        return ans;
    }
};
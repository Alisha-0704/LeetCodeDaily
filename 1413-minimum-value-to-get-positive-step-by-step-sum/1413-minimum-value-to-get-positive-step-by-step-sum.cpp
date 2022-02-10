class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int maxim=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            maxim=min(maxim,sum);
        }
        return 1-maxim;
    }
};
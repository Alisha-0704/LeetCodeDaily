class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int l=pow(2,nums.size());
        vector<vector<int>>res;
        for(int i=0;i<l;i++){
            vector<int>temp;
            for(int j=0;j<nums.size();j++){
                if(i&(1<<j))
                    temp.push_back(nums[j]);

                }
            res.push_back(temp);
        }
        return res;
            }
};
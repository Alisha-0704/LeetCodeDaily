class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<long long int,long long int>m;
        int n=nums.size();
        for(int i=0;i<n;i++){
            m[nums[i]]++;
            if(m[nums[i]]>=floor((n+1)/2))
                return nums[i];
        }
        return -1;
    }
};
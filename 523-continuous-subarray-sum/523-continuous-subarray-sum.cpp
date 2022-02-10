class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> st;          
        int sum = 0, r = 0;
        
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            
            int ans = sum % k;
            
            if(st.count(ans)){return true;}
            st.insert(r);
            r = ans;
        }
        return false;
    }
};
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<long long int,long long int>m;
        
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        vector<int>res;
        for(auto &e:m){
            if(e.second>floor(((double) nums.size())/3))
                res.push_back(e.first);
        }
        return res;
    }
};
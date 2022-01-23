class Solution {
public:
    map<vector<int>,int>m;
    void helper(vector<vector<int>>&res,vector<int>&nums,int idx,vector<int>&temp){
    if(temp.size()>=2)
        {   m[temp]++;
         if(m[temp]>1)
             return;
            res.push_back(temp);
     
        }
        if(idx>nums.size())
        {
              return ;
        }
        

        for(int i=idx;i<nums.size();i++){
            if(temp.size()>=1)
            {if(nums[i]<temp[temp.size()-1])
                continue;}
            
            temp.push_back(nums[i]);
            helper(res,nums,i+1,temp);
            temp.pop_back();
           
        }
        return;
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>temp;
            helper(res,nums,0,temp);
            
        return res;
    }
};
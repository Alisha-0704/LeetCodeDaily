class Solution {
public:
    void helper(vector<int>&nums,int start,int end,int & count,vector<int>& temp){
        if(start>=end)
            return;
        
        if(start==0){
            for(int i=start;i<nums.size();i++){
                temp.push_back(nums[i]);
                helper(nums,i+1,end,count,temp);
                temp.pop_back();
            }
        }
        else
            if(temp.size()<2){
                temp.push_back(nums[start]);
                helper(nums,start+1,end,count,temp);
                temp.pop_back();
            }
        else
        {
            int size=temp.size();
            if(temp[size-1]-temp[size-2]==nums[start]-temp[size-1])
            {
                count++;
                temp.push_back(nums[start]);
                helper(nums,start+1,end,count,temp);
                temp.pop_back();
            }
        }
   
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        int count=0;
        vector<int>temp;
        
        helper(nums,0,nums.size(),count,temp);
        return count;
    }
};
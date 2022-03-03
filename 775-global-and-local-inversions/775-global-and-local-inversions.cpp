class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
     
        for(int i=0;i<nums.size();i++){
           if(nums[i]==i || (i>=1 && nums[i-1]==i) || (i<nums.size()-1 && nums[i+1]==i))
               continue;
            else
                return false;
        }
        return true;
   
    }
    
};
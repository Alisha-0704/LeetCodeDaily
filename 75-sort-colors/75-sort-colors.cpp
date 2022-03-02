class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int,int>m;
        
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        
        for(int i=0;i<m[0];i++)
            nums[i]=0;
        for(int i=m[0];i<m[1]+m[0];i++)
            nums[i]=1;
        for(int i=m[1]+m[0];i<nums.size();i++)
            nums[i]=2;
        
        return;
    }
};
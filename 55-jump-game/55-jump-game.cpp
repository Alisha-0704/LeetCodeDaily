class Solution {
public:
    vector<int>num;
    bool canJump(vector<int>& nums) {
        num=nums;
        return findjump(num.size()-1);  
    }
    
    bool findjump(int n){
        if(num[n]==-1)
            return false;
        if(n==0)
            return true;
        num[n]=-1;
        for(int i=n-1;i>=0;i--){
            if(num[i]>=n-i && findjump(i))
                return true;
        }
        return false;
    }
};
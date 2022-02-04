class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        map<int,int>m;
        
        m[0]=-1;
        int maxlen=0;
        int count=0;
        
        for(int i=0;i<nums.size();i++){
            count=count+(nums[i]==1?1:-1);
            if(m.find(count)!=m.end()){
                maxlen=max(maxlen,i-m[count]);
            }
            else{
                m[count]=i;
            }
        }
        return maxlen;
    }
};
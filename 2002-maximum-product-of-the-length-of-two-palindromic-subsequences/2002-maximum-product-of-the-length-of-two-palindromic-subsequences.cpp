class Solution {
public:
    long long ans=0;
    bool ispal(string &x){
        int left=0;
        int right=x.length()-1;
        
        while(left<right){
            if(x[left]!=x[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
    void helper(string &s,string &s1,string &s2,int idx){
        if(idx>=s.length()){
            if(ispal(s1)&& ispal(s2)){
                long long val=(int)s1.length()*s2.length();
                ans=max(ans,val);
                
            }
            return;
        }
        
        s1.push_back(s[idx]);
        helper(s,s1,s2,idx+1);
        s1.pop_back();
        
        s2.push_back(s[idx]);
        helper(s,s1,s2,idx+1);
        s2.pop_back();
        
        helper(s,s1,s2,idx+1);
        return;
    }
    int maxProduct(string s) {
        string s1="",s2="";
        int idx=0;
        helper(s,s1,s2,idx);
        return ans;
    }
};
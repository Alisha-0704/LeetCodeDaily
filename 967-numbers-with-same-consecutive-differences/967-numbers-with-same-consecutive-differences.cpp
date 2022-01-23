class Solution {
public:
    void helper(vector<int>&v,int n,int k,int idx,string &s){
        if(idx==n-1){
            
            v.push_back(stoi(s));
            return;
        }
       
        for(int i=0;i<=9;i++){
             
            int k1=s.back()-'0';
            //cout<<abs(i-k1)<<endl;
            if(abs(i-k1)==k){
                
                s+=to_string(i);
                idx+=1;
                helper(v,n,k,idx,s);
                idx-=1;
                s.pop_back();
            }
        }
        return;
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>v;
        string s="";
        for(int i=1;i<=9;i++)
        {
            s+=to_string(i);
            helper(v,n,k,0,s);
            s.pop_back();
        }
        
        return v;
    }
};
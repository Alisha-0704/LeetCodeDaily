class Solution {
public:
    
    void helper(vector<int>& c, int target,vector<vector<int>>&v,vector<int>&t,int idx,set<vector<int>>&set){
        if(target==0)
        {   
            v.push_back(t);
         return;}
        
        if(idx>=c.size())
        {
            return;
        }
        
        for(int i=idx;i<c.size();i++){
             if (i > idx && c[i] == c[i - 1])
                continue;
            if(target-c[i]>=0){
            target-=c[i];
            t.push_back(c[i]);
            helper(c,target,v,t,i+1,set);
            target+=c[i];
            t.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        vector<vector<int>>v;
        set<vector<int>>set;
        vector<int>t;
        sort(c.begin(),c.end());
        helper(c,target,v,t,0,set);
        return v;
    }
};
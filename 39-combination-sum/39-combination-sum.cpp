class Solution {
public:
    vector<vector<int>>res;
     vector<int>temp;
    void bt(vector<int>&candidates,int target,int start,int end){
       
        
       if(start>=end || target<0)
            return;
        
        if(target==0)
        {
            res.push_back(temp);
          
        }
        
        for(int i=start;i<end;i++){
            
           temp.push_back(candidates[i]);
            bt(candidates,target-candidates[i],i,end);
            temp.pop_back();}
        return;
        }
        
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.size()==0)
            return {};
        
        int end= candidates.size();
        bt(candidates,target,0,end);
        return res;
    }
};
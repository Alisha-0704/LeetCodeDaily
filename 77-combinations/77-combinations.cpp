class Solution {
public:
    vector<vector<int>>res;
    void findcomb(int n,int k,int start,vector<int>&temp){
        if(temp.size()==k){
            res.push_back(temp);
            return ;
        }
        
        for(int i=start;i<=n;i++){
            temp.push_back(i);
       
            findcomb(n,k,i+1,temp);
         
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        if(n<k)
            return {};
        vector<int>temp;
        findcomb(n,k,1,temp);
        return res;
    }
};
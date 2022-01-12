class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
       typedef pair<int,int> p;
        
        if(mat.size()==0)
            return {};
        
        priority_queue<p,vector<p>,greater<p>>pq;
        
        vector<int>res;
        
        for(int i=0;i<mat.size();i++){
            int sum=0;
            for(int j=0;j<mat[0].size();j++){
                sum+=mat[i][j];
            }
            pq.push({sum,i});
        }
     
        while(k>0){
            res.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return res;
    }
};
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        
        for(int i=1;i<arr.size();i++){
            arr[i]=arr[i]^arr[i-1];
        }
        vector<int>res;
        for(int i=0;i<queries.size();i++){
            int l=queries[i][0];
            int r=queries[i][1];
            if(l==0)
              res.push_back(arr[r]);
            else
                res.push_back(arr[l-1]^arr[r]);   
        }
        return res;
        
    }
};

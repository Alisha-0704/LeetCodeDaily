class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        
        int lrange=intervals[0][0];
        int rrange=intervals[0][1];
        vector<vector<int>>res;
        res.push_back({lrange,rrange});
        
        int j=0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=res[j][1])
            {
             res[j][1]=max(res[j][1],intervals[i][1]);}
            else
            if(intervals[i][0]>res[j][1]){
                    res.push_back({intervals[i][0],intervals[i][1]});
                    j++;
            }
                
        }
        return res;
    }
};
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        if(trips.size()==0)
            return false;
        
        
        
        vector<int>count(10001,0);
        int maxdrop=0;
        for(int i=0;i<trips.size();i++){
            for(int j=trips[i][1] ;j<trips[i][2];j++){
                count[j]+=trips[i][0];
                
            }
            maxdrop=max(maxdrop,trips[i][2]);
        }
        int maxim=0;
        for(int i=0;i<=maxdrop;i++){
            maxim=max(maxim,count[i]);
        }
        if(maxim>capacity)
            return false;
        return true;
    }
};
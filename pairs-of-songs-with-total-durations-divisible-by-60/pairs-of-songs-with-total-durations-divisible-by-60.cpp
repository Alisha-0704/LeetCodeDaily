class Solution {
public:
   
    

    int numPairsDivisibleBy60(vector<int>& time) {
        for(int i=0;i<time.size();++i){
            time[i]=time[i]%60;
        }
        map<int,vector<int>>mp;
        for(int i=0;i<time.size();++i){
            mp[time[i]].push_back(i);
        }
        int count=0;
        for(int i=0;i<time.size();++i){
            if(time[i]!=0 && mp.find(60-time[i])!=mp.end()){
                count+=mp[60-time[i]].size()-(upper_bound(mp[60-time[i]].begin(),mp[60-time[i]].end(),i)-mp[60-time[i]].begin());
            }else if(time[i]==0){
                count+=mp[0].size()-(upper_bound(mp[0].begin(),mp[0].end(),i)-mp[0].begin());
            }
            
        }
        return count;
    }
};
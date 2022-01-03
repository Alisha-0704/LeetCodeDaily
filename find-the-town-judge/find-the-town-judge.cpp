class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size()==0 && n==1)
            return 1;
            
        map<int,vector<int>>m;
        vector<int>v(n+1,0);
        for(int i=0;i<trust.size();i++){
            v[trust[i][1]]++;
            m[trust[i][0]].push_back(trust[i][1]);
        }
        
        for(int i=0;i<trust.size();i++){
            if(m.find(trust[i][1])==m.end() && v[trust[i][1]]==(n-1))
                return trust[i][1];
        }
        return -1;
    }
};
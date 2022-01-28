class Solution {
public:
      struct Comp {
        bool operator()(const pair<int, string>& lhs, const pair<int, string>& rhs) const {
            if (lhs.first != rhs.first)
                return lhs.first < rhs.first;
            return lhs.second > rhs.second;
        }
      };
    vector<string> topKFrequent(vector<string>& words, int k) {
         map<string,int>m;
        
        for(int i=0;i<words.size();i++)
            m[words[i]]++;
        
        priority_queue<pair<int,string>,vector<pair<int,string>>,Comp>pq;
        for(auto &e:m)
        pq.push({e.second,e.first});
        
        
        vector<string>res;
        while(k--){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
class Solution {
public:
    int minSteps(string s, string t) {
        map<int,int>s1;
       
        
        for(int i=0;i<s.length();i++){
            s1[s[i]]++;
        }
        for(int i=0;i<t.length();i++){
            s1[t[i]]--;
        }
        int count=0;
        for(auto &e:s1){
            count+=abs(e.second);
        }
        return count;
    }
};
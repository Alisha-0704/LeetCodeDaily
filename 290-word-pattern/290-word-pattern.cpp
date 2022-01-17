class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string>v(pattern.length()+1);
        int j=0;
        for(int i=0;i<s.length();i++){
            if(s[i]!=' ')
            {
                v[j]+=s[i];
            }
            else
            j++;
        }
        
        map<string,char>ms;
        map<char,bool>visited;
        
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<endl;
        }
        for(int i=0;i<v.size();i++){
            if(ms.find(v[i])==ms.end() && visited[pattern[i]]==false){
                visited[pattern[i]]=true;
                ms[v[i]]=pattern[i];
            }
            else
                if(ms[v[i]]!=pattern[i])
                    return false;
                
        }
        return true;
    }
};
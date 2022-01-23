class Solution {
public:
    bool issub(string a, string s){
        int j=0;
        
        for(int i=0;i<s.length()&&j<a.length();i++){
            if(a[j]==s[i])
                j++;
        }
        return j==a.length();
    }
    string findLongestWord(string s, vector<string>& d) {
        
        string mstr="";
        for(string a:d){
            if(issub(a,s))
                if(a.length()>mstr.length() ||(a.length()==mstr.length() && a.compare(mstr)<0))
                    mstr=a;
        
        }
        return mstr;
    }
};
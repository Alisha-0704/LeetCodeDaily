class CombinationIterator {
public:
    int pos=0;
    vector<string>res;
    CombinationIterator(string c, int cl) {
        string s="";
        int start=0; 
        solve(c,cl,start,s);
    }
    void solve(string c, int cl,int start,string &s){
        if(start>=c.length())
        {
            if(s.length()==cl)
                res.push_back(s);
            return;
        }
        
        s.push_back(c[start]);
        solve(c,cl,start+1,s);
        s.pop_back();
        solve(c,cl,start+1,s);
        return;
    }
    string next() {
        string ans = res[pos++];
        return ans;
      
    }
    
    bool hasNext() {
       return pos<res.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
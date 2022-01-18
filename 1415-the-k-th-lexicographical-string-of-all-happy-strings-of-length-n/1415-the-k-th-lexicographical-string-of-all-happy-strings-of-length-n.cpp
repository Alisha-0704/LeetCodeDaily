class Solution {
public:
    vector<char> vals={'a','b','c'};
    vector<string>res;
    void helper(int n,int k,string s,int start){
        if(n==s.length()){
            res.push_back(s);
            //return;
        }
        else{
        for(int i=0;i<vals.size();i++){
            if(s.back()!=vals[i])
            {s.push_back(vals[i]);
                helper(n,k,s,i+1);
                s.pop_back();}
        }
        }
        return ;
    }
    string getHappyString(int n, int k) {

        string s;
        helper(n,k,s,0);
        
        return k>res.size()?"":res[k-1];
    }
};
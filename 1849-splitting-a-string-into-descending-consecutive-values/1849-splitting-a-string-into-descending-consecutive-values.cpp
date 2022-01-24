class Solution {
public:
    
    
    bool helper(string &s,int idx,vector<double>&res){
        string number="";
        if(idx==s.length())
        {
            
            for(int i=0;i<res.size()-1;i++){
                //cout<<res[i]<<" ";
                if(res[i]-res[i+1]!=1)
                    return false;
            }
            //cout<<endl;
            return res.size()>1?true:false;
        }
        if(idx<s.length()){
        for(int i=idx;i<s.length();i++){
            number=s.substr(idx,i-idx+1);
            if(!res.size()|| (res.size()>0 && res[res.size()-1]-stod(number)==1)) {
                res.push_back(stod(number));
                if(helper(s,i+1,res))
                    return true;
            //number.pop_back();
                res.pop_back();
        }
        }
        }
        return false;
    }
    bool splitString(string s) {
        if(s.length()<=1)
            return false;
        vector<double>res;
        return helper(s,0,res);
       
    }
};
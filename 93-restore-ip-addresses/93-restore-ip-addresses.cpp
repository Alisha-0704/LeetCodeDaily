class Solution {
public:
    
void backtrack(vector<string>&ans,string curr,string &s,int index,int numDots){
        if(numDots==3){
            if(s.size()-index<=3){
                if(index<s.size()-1 and s[index]=='0'){
                    return;
                } else {
                    string tmp=s.substr(index);
                    if(tmp.empty()){
                        return;
                    } else if(stoi(tmp)>=0 and stoi(tmp)<=255){
                        ans.push_back(curr+tmp);
                    }
                }
            }
        } else if(numDots>3 or index==s.size()){
            return;
        } else if(s[index]=='0'){
            curr.push_back(s[index]);
            curr.push_back('.');
            backtrack(ans,curr,s,index+1,numDots+1);
            curr.pop_back();
            curr.pop_back();
        } else {
            for(int i=1;i<=3;i++){
                if(index+i<s.size()){
                    string sub=s.substr(index,i);
                    int subVal=stoi(sub);
                    if(subVal>=0 and subVal<=255){
                        string tmp=curr+sub;
                        tmp.push_back('.');
                        backtrack(ans,tmp,s,index+i,numDots+1);
                    }
                }
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        if(s.size()>12 or s.size()<4){
            return {};
        } else {
            vector<string>ans;
            backtrack(ans,"",s,0,0);
            return ans;
        }
    }
};
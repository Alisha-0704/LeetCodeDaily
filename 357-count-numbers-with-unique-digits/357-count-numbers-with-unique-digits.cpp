class Solution {
private:
    vector<bool>generateCandForZero(){
        vector<bool>ans(10,false);
        ans[0]=true;
        return ans;
    }
    vector<bool>generate(string &num){
        vector<bool>ans(10,false);
        for(int i=0;i<num.size();i++){
            ans[num[i]-'0']=true;
        }
        return ans;
    }
    void backtrack(int &ans,string &num,int n){
        if(num.size()==n){
            return;
        } else {
            vector<bool>cnds;
            if(num==""){
                cnds=generateCandForZero();
            } else {
                cnds=generate(num);
            }
            for(int i=0;i<10;i++){
                if(!cnds[i]){
                    num.push_back(i+'0');
                    ans++;
                    backtrack(ans,num,n);
                    num.pop_back();
                }
            }
        }
    }
public:
    int countNumbersWithUniqueDigits(int n) {
        int ans=0;
        string num="";
        backtrack(ans,num,n);
        return ans+1;
    }
};
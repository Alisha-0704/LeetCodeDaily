class Solution {
public:
    vector<int>ans;
    void helper(vector<int>&res,string s,string num,int idx){
        long long number=0;
        if(idx>=num.length() && res.size()>2)
        {
            ans=res;
                return ;
        }
        
        for(int i=idx;i<num.length();i++){

            number=number*10+(num[i]-'0');
            if(number>=INT_MAX) return;
            if(num[idx]=='0' && i>idx)return ;
            if(res.size()<2 || number==((long long)res.back()+(long long)res[res.size()-2]))
            {
                res.push_back(number);
                helper(res,s,num,i+1);
                res.pop_back();
            }
        }
        return;
    }
    vector<int> splitIntoFibonacci(string num) {
        int n=num.length();
        if(n<=1)
            return {stoi(num)};
        vector<int>res;
        string s;
        helper(res,s,num,0);
        return ans;
    }
};
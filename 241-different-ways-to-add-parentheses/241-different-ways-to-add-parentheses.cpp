class Solution {
public:
    vector<int> diffWaysToCompute(string e) {
        vector<int>res;
        if(e.length()==0)
            return res;
        
        for(int i=0;i<e.length();i++){
            if(e[i]=='-' || e[i]=='+' || e[i]=='*'){
                vector<int>left= diffWaysToCompute(e.substr(0,i));
                vector<int>right=diffWaysToCompute(e.substr(i+1));
                
                for(auto &a:left){
                    for(auto &b: right){
                        //cout<<a<<" "<<b<<" ";
                        if(e[i]=='+'){
                            res.push_back(a+b);
                        }
                        else
                        if(e[i]=='-'){
                            res.push_back(a-b);
                        }
                        else
                        if(e[i]=='*'){
                            res.push_back(a*b);
                        }
                    }
                    //cout<<endl;
                }
                //cout<<endl;
            }
        }
        if(res.size()==0){
                stringstream geek(e);
                int x = 0;
                geek>>x;
            res.push_back(x);}
        return res;
    }
};
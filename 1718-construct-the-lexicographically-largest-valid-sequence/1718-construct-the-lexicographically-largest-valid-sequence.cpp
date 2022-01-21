class Solution {
private:
    bool backtrack(vector<int>&curr,vector<bool>&table,int &n,int index){
        if(index==curr.size()){
            return true;
        } else if(curr[index]!=0){
            return backtrack(curr,table,n,index+1);
        } else {
            for(int i=n;i>=1;i--){
                if(!table[i]){
                    table[i]=true;
                    curr[index]=i;
                    if(i==1){
                        if(backtrack(curr,table,n,index+1)){
                            return true;
                        }
                    } else {
                        if(index+i<2*n-1){
                            if(curr[index+i]==0){
                                curr[index+i]=i;
                                if(backtrack(curr,table,n,index+1)){
                                    return true;
                                }
                                curr[index+i]=0;
                            }
                        }
                    }
                    curr[index]=0;
                    table[i]=false;
                }
            }
            return false;
        }
    }
public:
    vector<int> constructDistancedSequence(int n) {
        vector<bool>table(n+1,false);
        vector<int>curr(2*n-1,0);
        backtrack(curr,table,n,0);
        return curr;
    }
};
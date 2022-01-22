class Solution {
private:
    void backtrack(int &ans,int curr,int &target,vector<int>&base,vector<int>&top,int index,bool &baseSelected){
        if(index==top.size()){
            if(abs(target-ans)>abs(target-curr)){
                ans=curr;
            } else if(abs(target-ans)==abs(curr-target)){
                ans=min(ans,curr);
            }
        } else if(!baseSelected){
            for(int i=0;i<base.size();i++){
                baseSelected=true;
                backtrack(ans,curr+base[i],target,base,top,index,baseSelected);
                baseSelected=false;
            }
        } else {
            backtrack(ans,curr,target,base,top,index+1,baseSelected);
            backtrack(ans,curr+top[index],target,base,top,index+1,baseSelected);
            backtrack(ans,curr+top[index]*2,target,base,top,index+1,baseSelected);
        }
    }
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int ans=INT_MAX,curr=0;
        bool baseSelected=false;
        backtrack(ans,curr,target,baseCosts,toppingCosts,0,baseSelected);
        return ans;
    }
};
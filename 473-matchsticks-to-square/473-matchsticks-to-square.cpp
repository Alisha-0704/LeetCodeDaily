class Solution {
public:
    bool helper(vector<int>& m,int idx,int target,int temp,vector<bool>&visited,int count){
        if(count==3)
            return true;
        if(temp==target){
            return helper(m,0,target,0,visited,count+1);}
        for(int i=idx;i<m.size();i++){
            if(visited[i]==false){
                visited[i]=true;
                temp+=m[i];
                if(helper(m,i+1,target,temp,visited,count))
                    return true;
                visited[i]=false;
                temp-=m[i];               
            }
        }
        return false;
    }
    bool makesquare(vector<int>& m) {
        int target=0;
        
        target=accumulate(m.begin(),m.end(),target);
        
        if(target%4!=0)
            return false;
        target=target/4;
        int temp=0;
        vector<bool>visited(m.size(),false);
        return helper(m,0,target,temp,visited,0);
    }
};
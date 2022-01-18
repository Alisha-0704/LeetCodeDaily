class Solution {
public:
    int count=0;
    void helper(int n,vector<int>&visited,vector<int>&temp){
        if(temp.size()==n)
        {count++;
         return;}
        
        
        for(int i=1;i<=n;i++){
           // cout<<i<<" "<<temp.size()<<endl; 
            if((i%(temp.size()+1)==0 || (temp.size()+1)%i==0)  && visited[i]==0){
                visited[i]=1;
                temp.push_back(i);
                helper(n,visited,temp);
                visited[i]=0;
                temp.pop_back();              
            }
                
        }
        return;
    }
    int countArrangement(int n) {
        if(n==0)
            return 0;
        vector<int>visited(n+1,0);
        vector<int>temp;
        helper(n,visited,temp);
        return count;
        
    }
};
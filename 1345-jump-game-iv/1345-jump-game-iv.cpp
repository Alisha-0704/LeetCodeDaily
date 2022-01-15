class Solution {
public:
    bool ismap(map<int,vector<int>>&m,int a){
        return (m.find(a)!=m.end());
           
    }
    int minJumps(vector<int>& arr) {
        if(arr.size()==0)
            return 0;
        map<int,vector<int>>m;
        for(int i=0;i<arr.size();i++)
            m[arr[i]].push_back(i);
        
       queue<int>q;
        q.push(0);
        int ans=-1;
        while(!q.empty()){
            int s=q.size();
            ans++;
            
            while(s--){
                int idx=q.front();
                q.pop();
                int element=arr[idx];
                
                if(idx-1>=0 && ismap(m,arr[idx-1]))
                    q.push(idx-1);
                
                if(idx+1==arr.size()-1 && ismap(m,arr[idx+1]))
                    return ans+1;
                if(idx+1<arr.size()-1 && ismap(m,arr[idx+1]))
                    q.push(idx+1);
                
                if(!ismap(m,element))
                    continue;
                
                for(auto &e:m[element]){
                    if(e!=idx)
                    {
                        if(e==arr.size()-1)
                            return ans+1;
                        else
                            q.push(e);
                    }
                }
                m.erase(arr[idx]);
                
            }
            
        }
        return ans;
    }
};
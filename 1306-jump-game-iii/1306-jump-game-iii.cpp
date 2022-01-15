class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        
        queue<int>q;
        
        q.push(start);
        while(!q.empty()){
            int a=q.front();
            q.pop();
            if(arr[a]==0)
                return true;
            
            if(arr[a]<0)
                continue;
            
            if(arr[a]+a<=n-1)
                q.push(arr[a]+a);
            if(a-arr[a]>=0)
                q.push(a-arr[a]);
            arr[a]=-arr[a];
            
        }
        return false;
    }
};
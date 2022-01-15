class KthLargest {
public:
    int n;
    priority_queue<int,vector<int>,greater<int>>q;
    KthLargest(int k, vector<int>& nums) {
        n=k;
        for(auto &e :nums){
            q.push(e);
        }
        while(q.size()>k){
            q.pop();
        }
    }
    
    int add(int val) {
        q.push(val);
        while(q.size()> n)
            q.pop();
        
        return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
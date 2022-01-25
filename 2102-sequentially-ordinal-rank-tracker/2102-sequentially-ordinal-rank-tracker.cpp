class SORTracker {
public:
    #define pis pair<int, string> 
    struct cmp{
        bool operator()(pis &a, pis & b){
            if(a.first == b.first) return a.second > b.second; 
            return a.first < b.first; 
        }
    };
    
    struct cmpRev{
        bool operator()(pis &a, pis & b){
            if(a.first == b.first) return a.second < b.second; 
            return a.first > b.first; 
        }
    };
    
    int i = 0; 
    priority_queue<pis, vector<pis>, cmp> maxHeap; 
    priority_queue<pis, vector<pis>, cmpRev> minHeap; 
    SORTracker() {
        
    }
    
    void add(string name, int score) {
        while(minHeap.size()<i+1 && maxHeap.size()){
            minHeap.push(maxHeap.top()); 
            maxHeap.pop(); 
        }
        
        minHeap.push({score, name}); 
        if(minHeap.size() > i+1) {
            maxHeap.push(minHeap.top()); 
            minHeap.pop(); 
        }
    }
    
    string get() {
        i++; 
        auto temp = minHeap.top();
        minHeap.pop(); 
        add(temp.second, temp.first); 
        return temp.second; 
    }

};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */
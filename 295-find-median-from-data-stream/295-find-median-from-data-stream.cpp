class MedianFinder {
public:
    priority_queue<int> mini;
    priority_queue<int, vector<int>, greater<int>> maxi;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
    if(maxi.empty() and mini.empty()){
            mini.push(num);
        }
        else{
            int m = maxi.size();
            int n = mini.size();
            if(m==n){
                int median = (maxi.top()+mini.top()) / 2;
                if(num>median)
                    maxi.push(num);
                else
                    mini.push(num);
            }
            else if(m>n){
                int median = maxi.top();
                if(num>median){
                    mini.push(maxi.top());
                    maxi.pop();
                    maxi.push(num);
                }
                else mini.push(num);
            }
            else{
                int median = mini.top();
                if(num>median) maxi.push(num);
                else{
                    maxi.push(mini.top());
                    mini.pop();
                    mini.push(num);
                }
            }
        }
    }
    
    double findMedian() {
   int m = maxi.size();
        int n = mini.size();
        double median;
        if(m==n)
            median = double(maxi.top()+mini.top()) /(double) 2;
        else if(m>n)
            median = (double) maxi.top();
        else
            median = (double) mini.top(); 
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
class StockSpanner {
public:
    vector<int>v;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int count=0;
        for(int i=v.size()-1;i>=0;i--)
        {
            if(v[i]>price)
            {
                v.push_back(price);
                return count+1;
            }
            count++;
            
        }
        //cout<<price<<endl;
        v.push_back(price);
        return count+1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
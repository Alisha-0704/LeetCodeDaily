class StockPrice {
public:
    multiset<int> ms;
    map<int,int>m;
    
    int latest=0;
  
    StockPrice() {
        
    }
  
    void update(int timestamp, int price) {
        if ( m[timestamp] ) {
            ms.erase ( ms.find(m[timestamp]) );
        }
        m[timestamp]=price;
        //cout<<timestamp<<m[timestamp]<<endl;
        latest=max(latest,timestamp);
        ms.insert ( price );
        m[timestamp] = price;
        
        
    }
    
    int current() {
        return m[latest];
    }
    
    int maximum() {
        return *(ms.rbegin());
    }
    
    int minimum() {
        return *(ms.begin());
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
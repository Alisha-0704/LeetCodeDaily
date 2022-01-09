class MyCalendar {
public:
    vector<vector<int>>cal;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(int i=0;i<cal.size();i++){
            if((cal[i][0]<=start && start<cal[i][1])||(cal[i][0]<end && end<=cal[i][1])|| (cal[i][0]>=start && end>=cal[i][1]))
                return false;
        }
    vector<int> interval;
    interval.push_back(start);
    interval.push_back(end);
    
    cal.push_back(interval);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
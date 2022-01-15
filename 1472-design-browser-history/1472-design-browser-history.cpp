class BrowserHistory {
public:
    vector<string>v;
    int x;
    BrowserHistory(string homepage) {
       v.push_back(homepage);
        x=0;
    }
    
    void visit(string url) {
        v.erase(v.begin()+x+1,v.end());
        v.push_back(url);
        x++;
    }
    
    string back(int steps) {
        x=max(0,x-steps);
        return v[x];
    }
    
    string forward(int steps) {
        x=min((int)(v.size()-1),(int)(x+steps));
        return v[x];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
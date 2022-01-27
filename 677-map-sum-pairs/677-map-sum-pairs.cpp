

class MapSum {
    map<string,int>m;
    
public:
    struct trie{    
    vector<trie*>children{vector<trie*>(26,NULL)};
    int score=0; 
    }*root,*curr;
    
    MapSum() {
        root=new trie();
    }
    
    void insert(string key, int val) {
        int d=val-m[key];
        m[key]=val;
        curr=root;
        (curr->score)+=d;
        for(auto &c:key){
            if(!curr->children[c-'a'])
                curr->children[c-'a']= new trie();
            curr=curr->children[c-'a'];
            (curr->score)+=d;
            
        }
        
        
        
    }
    
    int sum(string prefix) {
        curr= root;
        for(auto &c:prefix){

            curr=curr->children[c-'a'];
            if(curr==NULL)
                return 0;
        }
        return curr->score;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
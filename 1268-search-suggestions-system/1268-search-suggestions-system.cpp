class Trie{
    public:
    struct trie{
        vector<trie *> children{vector<trie *>(26, NULL)};
        bool iseow=false;
    }*Root, *curr;
    
    Trie(){
        Root=new trie();
    }
    void insert(string &s){
        curr= Root;
        for(char &c:s){
            if(!curr->children[c-'a'])
                curr->children[c-'a']=new trie();
            curr=curr->children[c-'a'];
        }
        curr->iseow=true;
    }
    void dfs(trie* curr,string &prefix,vector<string> &result){
        if(result.size()==3)
            return ;
        if(curr->iseow==true)
            result.push_back(prefix);
        
        for(char c='a';c<='z';c++){
            if(curr->children[c-'a']){
                prefix+=c;
                dfs(curr->children[c-'a'],prefix,result);
                prefix.pop_back();
            }
        }
    }
    
    vector<string>getwordsstartingwith(string &prefix){
        curr=Root;
        vector<string>result;
        for(char &c:prefix){
            if(!curr->children[c-'a'])
                return result;
            curr=curr->children[c-'a'];
        }
        dfs(curr,prefix,result);
        return result;
    }
};


class Solution {
public:
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie trie1=Trie();
        vector<vector<string>>result;
        for(string &s:products){
            trie1.insert(s);
        }
        string prefix;
        for(char &c:searchWord)
        {
            prefix+=c;
            result.push_back(trie1.getwordsstartingwith(prefix));
        }
        return result;
    }
};
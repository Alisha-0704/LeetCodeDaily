class WordDictionary {
public:
    struct trie{
        vector<trie*>ch{vector<trie*>(26,NULL)};
        bool iseow=false;
    }*Root,*curr;
    WordDictionary() {
        Root=new trie();
    }
    
    void addWord(string word) {
        curr= Root;
        
        for(auto &c:word){
            if(!curr->ch[c-'a'])
                curr->ch[c-'a']=new trie();
            curr=curr->ch[c-'a'];
            
        }
        curr->iseow=true;
    }
    bool helper(string word, trie* curr){
        for(int i=0;i<word.length();i++){
            if(word[i]=='.'){
                for(char c=0;c<26;c++){
                    if(curr->ch[c] && helper(word.substr(i+1),curr->ch[c])) 
                        return true;
                }
                return false;
            }
            else{
            if(!curr->ch[word[i]-'a']){
                return false;
            }
            curr = curr->ch[word[i]-'a'];
            }
        }
        if(curr->iseow) {
            return true; 
        }
        return false;  
       
    }
    bool search(string word) {
        curr=Root;
       return helper(word,curr);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
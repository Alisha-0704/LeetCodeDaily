class Trie{
    public:
    struct trie{
    vector<trie*>children{vector<trie*>(26,NULL)};
    string word="";
    }*Root,*curr;
    
    Trie(){
        Root=new trie();
    }
    
    void insert(string &s){
        curr=Root;
        for(char &c:s){
            if(!curr->children[c-'a'])
                curr->children[c-'a']=new trie();
            curr=curr->children[c-'a'];
        }
        curr->word=s;
        
    }
    string check(string &s){
    curr=Root;
          
            for(auto &c: s){
                if(!curr->children[c-'a'] || curr->word!="")
                    break;
                curr=curr->children[c-'a'];
            }
            return(curr->word!=""?curr->word:s);
    }
    
    
};


class Solution {
public:
    vector<string> simple_tokenizer(string s)
    {
        vector<string>res;
        stringstream ss(s);
        string word;
        while (ss >> word) {
        res.push_back(word);
     }
        return res;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie=Trie();
        
        for(string &s:dictionary){
            trie.insert(s);
        }
        
        string ans="";
       vector<string>sen= simple_tokenizer(sentence);
        for(auto &s:sen){
             if(ans.length()>0)
               ans.push_back(' ');
            ans+=trie.check(s);
        }
        return ans;
    }
};
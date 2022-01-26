class Solution {
public:
	// intializing structure of trie 
    struct Trie{
        unordered_map<char,Trie*> mp; // to store sequence of characters the particular string have
        bool end; // end defines the end of our string in trie
        Trie(){
            end = false;
        }
    };
	// insertion of all strings
    void insert(string& str){
        Trie* curr = root;
        for(auto& it:str){
            if(!curr->mp.count(it))
                curr->mp[it] = new Trie;
            curr = curr->mp[it];
        }
        curr->end = true;
    }
	// checking for conditions according to question
    int go(string str,string pat){
        int j = 0;
        Trie* curr = root;
        for(auto& it:str){
            if(j < pat.size() && it == pat[j]){
                curr = curr->mp[it];
                j++;
            }else if(j < pat.size() && it != pat[j] && it >= 97 && it <= 122){
                curr = curr->mp[it];
            }else{
                if(j >= pat.size() && it >= 97 && it <= 122){
                    curr = curr->mp[it];
                }else{
                    return false;
                }
            }
        }
        return j >= pat.size() ? true:false;
    }
	// intializing root as start of trie
	
    Trie* root = new Trie;
	
	// main function
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans(queries.size(),false);
        for(auto& it:queries)
            insert(it);
        for(int i=0;i<queries.size();i++)
            ans[i] = go(queries[i],pattern);
        return ans;
    }
};
class Trie {
private:
    vector<Trie *> child;
    bool isEnd;
public:
    Trie () : child(26, NULL) {
        isEnd = false;
    }
    
    void insert(string &s) {
        Trie *curr = this;
        for (char &c : s) {
            int cIndex = c - 'a';
            if (curr->child[cIndex] == NULL) {
                curr->child[cIndex] = new Trie();
            }
            curr = curr->child[cIndex];
        }
        curr->isEnd = true;
    }
    
    bool helper(Trie *curr, string &s, int i, int cnt) {
        
        if (cnt > 1) return false;
        
        if (i == s.size()) {
            if (curr->isEnd && cnt == 1) return true;
            return false;
        }
        
        for (int k = 0; k < 26; k++) {
            if (curr->child[k] == NULL) continue;
            if (helper(curr->child[k], s, i + 1, (k == s[i] - 'a' ? cnt : cnt + 1))) return true;
        }
        
        return false;
    }
    
    bool strangeSearch(string &s) {
        return helper(this, s, 0, 0);
    }
};

class MagicDictionary {
private:
    Trie trie;
public:
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        for (string &eachS : dictionary) {
            trie.insert(eachS);
        }
    }
    
    bool search(string searchWord) {
        return trie.strangeSearch(searchWord);
    }
};
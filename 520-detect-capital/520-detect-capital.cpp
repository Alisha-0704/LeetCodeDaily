class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.length()<=1)
            return true;
        int k=0;
        for(int i=0;i<word.length();i++){
            if(word[i]>=65 && word[i]<=90)
                k++;
        }
        if((k==1 && (word[0]>=65 && word[0]<=90))|| k==word.length()|| k==0)
            return true;
        return false;
    }
};
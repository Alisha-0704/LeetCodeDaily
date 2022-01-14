class Solution {
public:
    bool isnum(char c){
        return (c>='0' && c<='9');
    }
    bool isNumber(string s) {
        bool ee = false;
        bool eene = false;
        int cur = 0;
        
        if(s[cur]=='+' || s[cur]=='-')
            cur++;
        
        while(isnum(s[cur]))
            cur++;
        
        if(s[cur]=='.')
        {
             if (cur == 0 || !isnum(s[cur - 1])) {
                 if (cur + 1 < s.size() && isnum(s[cur + 1]))
                    cur += 1;
             }
            else
                cur++;
        }
        
        while (cur < s.size() && isnum(s[cur])) {
            cur += 1;
        }
        
        if (cur > 0 && (s[cur - 1] == '.' || isnum(s[cur - 1]))  && (s[cur] == 'e' || s[cur] == 'E')) {
            ee = true;
            cur += 1;
        }
        
         if (cur < s.size() && ee && (s[cur] == '-' || s[cur] == '+'))
            cur += 1;
        
    
        while (cur < s.size() && isnum(s[cur])) {
            cur += 1;
            eene = true;
        }
        bool ret =  (cur == s.length());
        ret = ret & ((ee && eene) || (!ee));  
        return ret;

    }
};
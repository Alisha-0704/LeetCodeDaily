class Solution {
public:
    bool isRobotBounded(string s) {
        if(s.length()==0)
            return false;
        pair<int,int>dest={0,0};
        char currdir='N';
        for(int i=0;i<s.length();i++){
            if(s[i]=='G'){
               dest.second+= currdir=='N'?1:0;
               dest.second+= currdir=='S'?-1:0;
                dest.first+= currdir=='E'?1:0;
                dest.first+= currdir=='W'?-1:0;
                
            }
            else{
                char incoming = s[i];
                if(currdir == 'N'){
                    currdir = incoming == 'L' ? 'W' : 'E';
                }
                else if(currdir == 'W'){
                    currdir = incoming == 'L' ? 'S' : 'N';
                }
                else if(currdir == 'S'){
                    currdir = incoming == 'L' ? 'E' : 'W';
                }
                else{
                   currdir = incoming == 'L' ? 'N' : 'S';
                }
            } 
        }
        if(dest.first==0 && dest.second==0 || currdir!='N')
            return true;
        return false;
    }
};
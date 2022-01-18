class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        if(f.size()==1){
            if(f[0]==0 && n<=1)
                return true;
            if(f[0]==1 && n>=1)
                return false;            
        }
        int c=0;
        for(int i=0;i<f.size();i++){
            if(i==0){
                if(f[i]==0 &&f[i+1]==0){
                    f[i]=1;
                    c++;
                }
            }
            else
            if(i==f.size()-1){
                if(f[i]==0 &&f[i-1]==0){
                    f[i]=1;
                    c++;
                }                
            }
            else
            {
                if(f[i]==0 && f[i+1]==0 && f[i-1]==0){
                    f[i]=1;
                    c++;
                }
            }
        }
        if(c>=n)
            return true;
        return false;
    }
};
class Solution {
public:
    int left=0;
    int findpower(int num){
        
        if(num==1)
            return 0;
        
       
        
        if(num%2==0){
            left=1+findpower(num/2);
        }
        else
            left=1+findpower(3*num+1);
        
        return left;
        
    }
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>>listing;
        if(lo>hi)
            return -1;
        for(int i=lo;i<=hi;i++){
            vector<int>dp(i+1,-1);
            int x=findpower(i);
            listing.push_back(make_pair(x,i));
        }
        sort(listing.begin(),listing.end());
        
        return listing[k-1].second;
    }
};
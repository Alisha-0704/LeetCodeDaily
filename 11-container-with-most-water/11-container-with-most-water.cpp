class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size()<=1)
            return 0;
        
        int r=height.size()-1;
        int l=0;
        int ans=0;
        while(l<r){
            int lh=height[l];
            int rh=height[r];
            ans=max(ans,min(lh,rh)*(r-l));
            if(lh<rh)
                l++;
            else
                r--;
        }
        return ans;
    }
};
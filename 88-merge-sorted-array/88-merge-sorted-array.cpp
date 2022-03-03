class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,j=0;
        if(nums2.empty() || nums1.empty())
            return;
        
        while(nums1.size()>i && nums2.size()>j){
            //cout<<nums1[i]<<" "<<nums2[j]<<" "<<i<<" "<<j<<endl;
            if(nums2[j]<=nums1[i]){
                nums1.insert(nums1.begin()+i,nums2[j]);
                nums1.pop_back();
                j++;
                i++;
            }
            else
                i++;
        }
        while(j<n){
           nums1[m+j]=nums2[j];
            j++;
        }
        return;
    }
};
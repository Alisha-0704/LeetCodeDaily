class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int i,n,kl=0;int a[100000];
        n=nums.size();
        k=k%n;
            //cout<<"[";
            for(i=n-k;i<=n-1;i++){
                //cout<<nums[i]<<",";
                a[kl++]=nums[i];
            }
            for(i=0;i<n-k;i++){
                a[kl++]=nums[i];
            }
            for(i=0;i<n;i++){
                nums[i]=a[i];
            }            
    
        
    }
};
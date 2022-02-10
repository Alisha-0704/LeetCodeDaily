class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum=0;
        int sub=0;
        int n=arr.size();
        for(int i=0;i<arr.size();i++){
            sub=(n-i)*(i+1);
            
            if(sub%2==0)
                sub=sub/2;
            else
                sub=(sub/2)+1;
            
            sum+=sub*arr[i];
        }
        return sum;
    }
};
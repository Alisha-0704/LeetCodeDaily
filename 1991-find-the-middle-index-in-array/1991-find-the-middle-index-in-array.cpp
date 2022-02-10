class Solution {
public:
    int findMiddleIndex(vector<int>& arr) {
        int totalsum = accumulate(arr.begin() , arr.end() , 0);
        int sum = 0;
        for(int i=0 ; i<arr.size() ; i++){
            if(sum==(totalsum-sum-arr[i])){
                return i;
            }
            sum += arr[i];
        }
        return -1;
    }
};
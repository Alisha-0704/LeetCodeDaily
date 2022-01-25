class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size()<3)
            return false;
        int i=0;
        int j=arr.size()-1;
        while(i<j){
            if(arr[i]==arr[i+1])
                return false;
            
            if(arr[i]>arr[i+1])
                break;
            i++;
        }
        if(i==0)
            return false;
        if(i==j)
            return false;
        while(i<j){
            //cout<<i<<endl;
            if(arr[i]<=arr[i+1])
                return false;
            i++;
        }
        return true;
    }
};
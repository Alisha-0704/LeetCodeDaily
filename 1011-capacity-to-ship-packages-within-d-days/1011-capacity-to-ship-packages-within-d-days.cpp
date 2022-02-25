class Solution {
public:
        bool isPossible(vector<int> weights, int days,int mid){
        
        int weightSum=0;
        int daysCount=1;
        
        for(int i=0;i<weights.size();i++){
            
            if(weightSum+weights[i] <= mid){
                weightSum+=weights[i];
            }
            else{
                daysCount++;
                weightSum=0;
                if(daysCount> days || weights[i]>mid){
                    return false; 
                }     
                 weightSum+=weights[i];      
            }
          
        }
          return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        
        int sum=0;
        
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
        }
        
        int s=0;
        int e=sum;
        int mid=s+(e-s)/2;
        int ans=-1;
        while(s<=e){
            
            if(isPossible(weights,days,mid)){
                ans=mid;
                e=mid-1;
            }
            else
                s=mid+1;
            
            mid=s+(e-s)/2;
        }
        return ans;
        
    }
};
//0 
// 2 5 4
//?
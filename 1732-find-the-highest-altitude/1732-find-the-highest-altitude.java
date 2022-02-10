class Solution {
    public int largestAltitude(int[] gain) {
        //As biker starts his trip on point 0 with altitude equal 0 so that can also be the highest altitude
        // In the for loop we are starting i value from 1 because we want to add the previous element in it so we have checked if element at index 0 is max or not
        int max = Math.max(0,gain[0]);
        int sum =0;
        
        for(int i=1;i<gain.length;i++){
            gain[i]+=gain[i-1];
            max = Math.max(max,gain[i]);
    
        }
        return max;
        
    }
}
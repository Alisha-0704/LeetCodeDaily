class Solution {
public:
    int numTrees(int n) {
        vector<int> result(n+1, 0);
        
        return numSubTrees(n, result);
    }
    
    int numSubTrees(int n, vector<int> &result) {
        if (n == 0)
            return 1;
    
        if (result[n] != 0)
            return result[n];
        
        for (int x = 1; x <= n; ++x) {
            result[n] += (numSubTrees(x-1, result) * numSubTrees(n-x, result)) ;
        }
        return result[n];
    }
};
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        int k=0;
        for(int i=0;i<=n;i++){
            bitset<32> b1(i);
            k=b1.count();
            ans.push_back(k);
        }
        return ans;
    }
};
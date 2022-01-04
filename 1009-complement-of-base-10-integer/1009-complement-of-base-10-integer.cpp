class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)
            return 1;
        if(n==1)
            return 0;
        for(int i=0;i<128;i++){
            int k=pow(2,i);
            if(n<k)
                return n^(k-1);
        }
        return -1;
    }
};
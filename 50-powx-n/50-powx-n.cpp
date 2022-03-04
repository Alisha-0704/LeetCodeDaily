class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)
            return 1.0;
        long long nextpow=n;
        if(nextpow<0)
            nextpow=-1*nextpow;
        double result=1.0;
        while(nextpow>0){
          if(nextpow%2==1)
          {result=result*x;  
            nextpow=nextpow-1;}
            else
            {x=x*x;  
            nextpow=nextpow/2;}              
        }
        if(n<0)
            return (double) (1.0)/(double)result;
        return result;
    }
};
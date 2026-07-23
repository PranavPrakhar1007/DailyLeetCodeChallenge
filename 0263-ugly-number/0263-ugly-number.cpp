class Solution {
public:
    bool isUgly(int n) {
        if(n<=0) return false;
        int allowedPrimes[3] = {2,3,5};
        for(int prime : allowedPrimes)
        {
            while(n%prime==0) n/=prime;
        }
        return n==1;
    }
};
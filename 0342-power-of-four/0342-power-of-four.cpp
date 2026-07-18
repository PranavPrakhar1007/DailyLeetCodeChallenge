class Solution {
public:
    bool isPowerOfFour(int n) {
        long long val = 1;
        while(val<=n)
        {
            if(val==n) return true;
            val*=4;
        }
        return false;
    }
};
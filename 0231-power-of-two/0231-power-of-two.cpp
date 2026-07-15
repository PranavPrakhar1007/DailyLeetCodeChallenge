class Solution {
public:
    bool isPowerOfTwo(int n) {
        int power = 0;
        while(power<31)
        {
            if(pow(2,power)==n) return true;
            power++;
        }
        return false;
    }
};
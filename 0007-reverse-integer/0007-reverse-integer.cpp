class Solution {
public:
    int reverse(int x) {
        long long rev = 0;
        while(x!=0)
        {
            int rem = x%10;
            rev = rev*10 + rem*1.0;
            if(rev>INT_MAX) return 0;
            if(rev<INT_MIN) return 0;
            x = x/10;
        }
        return rev;
    }
};
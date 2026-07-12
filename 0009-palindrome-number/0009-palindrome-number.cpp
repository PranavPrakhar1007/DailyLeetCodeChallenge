class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int org = x;
        long long rev = 0;
        while(x>0)
        {
            int rem = x%10;
            rev = rev*10+rem*1.0;
            if(rev>INT_MAX) return false;
            if(rev<INT_MIN) return false;
            x=x/10;
        }
        if(rev==org) return true;
        return false;
    }
};
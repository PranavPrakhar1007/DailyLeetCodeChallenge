class Solution {
public:
    int climbStairs(int n) {
        if(n<=3) return n;
        int currentways = 0;
        int prev1 = 3;
        int prev2 = 2;
        for(int i=4;i<=n;i++)
        {
            currentways = prev1 + prev2;
            prev2 = prev1;
            prev1 = currentways;
        }
        return currentways;
    }
};
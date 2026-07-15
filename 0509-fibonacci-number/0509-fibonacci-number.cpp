class Solution {
public:
    int fib(int n) {
        int secondLast = 0, last =1;
        int curr = 0;
        if(n==1) return 1;
        for(int i=1;i<n;i++)
        {
            curr = secondLast+last;
            secondLast = last;
            last = curr;
        }
        return curr;
    }
};
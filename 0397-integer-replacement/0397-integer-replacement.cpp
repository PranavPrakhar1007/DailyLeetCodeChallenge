class Solution {
public:
    int integerReplacement(int n) {
        int cnt = 0;
        unsigned int un = n;
        while(un!=1)
        {
            if((un&1)==0) un>>=1;
            else if(un==3 || (un&2)==0) un--;
            else un++;
            cnt++;
        }
        return cnt;
    }
};
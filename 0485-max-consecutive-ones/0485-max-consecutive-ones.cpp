class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxcnt = 0;
        int cnt=0;
        for(int x:nums)
        {
            if(x==0) cnt=0;
            else 
            {
                cnt++;
                maxcnt = max(cnt,maxcnt);
            }
        }
        return maxcnt;
    }
};